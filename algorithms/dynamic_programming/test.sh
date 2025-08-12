#!/bin/bash

EXE="./a.out"
TESTDIR="./HonestWorkerTests"
TIME_LIMIT=1 # seconds

INPUT_DIR="$TESTDIR/input"
OUTPUT_DIR="$TESTDIR/output"

for input_file in "$INPUT_DIR"/*; do
    testname=$(basename "$input_file")
    expected_file="$OUTPUT_DIR/$testname"

    if [[ ! -f "$expected_file" ]]; then
        echo "Missing expected output for $testname"
        exit 1
    fi

    # Run with timeout
    output=$(timeout $TIME_LIMIT "$EXE" < "$input_file")
    exit_code=$?

    if [[ $exit_code -eq 124 ]]; then
        echo "$testname: TLE"
        exit 1
    elif [[ $exit_code -ne 0 ]]; then
        echo "$testname: RUNTIME ERROR (code $exit_code)"
        exit 1
    fi

    # Compare results
    if cmp -s <(echo "$output") "$expected_file"; then
        echo "$testname: OK"
    else
        echo "$testname: WA"
        echo "Expected:"
        cat "$expected_file"
        echo "Got:"
        echo "$output"
        exit 1
    fi
done

echo "All tests passed!"
