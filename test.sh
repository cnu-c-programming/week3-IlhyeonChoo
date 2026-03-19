#!/bin/bash
cd "$(dirname "$0")"

path_code="code"
path_test="testset"
CC="gcc"

shopt -s nullglob
c_files=("$path_code"/*.c)
shopt -u nullglob

if [ ${#c_files[@]} -eq 0 ]; then
    echo "No .c files in $path_code"
    exit 1
fi

IFS=$'\n' sorted=($(printf '%s\n' "${c_files[@]}" | sort))
unset IFS

for f in "${sorted[@]}"; do
    name=$(basename "$f" .c)
    expected="$path_test/${name}-out.txt"
    if [ ! -f "$expected" ]; then
        echo "$name: SKIP (no ${name}.txt in Test)"
        continue
    fi

    infile="$path_test/${name}-in.txt"
    outbin="$path_code/$name"

    $CC "$f" -o "$outbin" 2>/dev/null
    if [ ! -f "$outbin" ] || [ ! -x "$outbin" ]; then
        echo "$name: COMPILE FAIL"
        continue
    fi

    actual="$path_test/actual-${name}.txt"
    if [ -f "$infile" ]; then
        "./$outbin" < "$infile" > "$actual"
    else
        "./$outbin" > "$actual"
    fi

    if diff -q "$actual" "$expected" > /dev/null 2>&1; then
        echo "${name}.txt: PASS"
    else
        echo "${name}.txt: FAIL"
    fi
    rm -f "$actual"
done
