#!/bin/bash

TIME_LIMIT=1
TEST_DIR="./tests"
EXECUTABLE="./k"
TMP_OUT="tmp.out"

for input in "$TEST_DIR"/*.in; do
    base=$(basename "$input" .in)
    answer="$TEST_DIR/$base.ans"

    timeout "$TIME_LIMIT" "$EXECUTABLE" < "$input" > "$TMP_OUT"
    status=$?

    if [ $status -eq 124 ]; then
        echo "[${base}] Time Limit Exceeded"
        exit 1
    fi

    if ! cmp -s "$TMP_OUT" "$answer"; then
        echo "[${base}] Wrong Answer"
        echo "Expected:"
        cat "$answer"
        echo "Got:"
        cat "$TMP_OUT"
        exit 1
    fi

    echo "[${base}] OK"
done

rm -f "$TMP_OUT"
