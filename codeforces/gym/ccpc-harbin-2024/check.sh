name="b"

make ${name}
make ${name}_std

while true; do
    python ./gen.py > ${name}.in
    ./${name} < ${name}.in > ${name}.out;
    ./${name}_std < ${name}.in > ${name}.ans;
    if diff -w ${name}.out ${name}.ans; then
        echo "AC"
    else
        echo "WA"
        break
    fi
done
