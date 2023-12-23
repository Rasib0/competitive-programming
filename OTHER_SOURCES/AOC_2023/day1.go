package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func day_1_part1_main() {
	sum := 0

	input := os.Stdin
	scanner := bufio.NewScanner(input)

	for scanner.Scan() {
		line := scanner.Text()
		term := ""

		for i := range line {
			if line[i] >= '0' && line[i] <= '9' {
				term += string(line[i])
				break
			}
		}

		for temp := range line {
			j := len(line) - 1 - temp
			if line[j] >= '0' && line[j] <= '9' {
				term += string(line[j])
				break
			}
		}

		parsed_term, err := strconv.Atoi(term)
		if err != nil {
			fmt.Println("Error parsing term")
			return
		}

		sum += parsed_term
	}

	fmt.Println(sum)
}

type Tuple struct {
	First  string
	Second int
}

func day1_part2_main() {
	sum := 0

	strings := []Tuple{
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9},
		{"zero", 0},
		{"0", 0},
		{"1", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
	}

	strings_rev := []Tuple{
		{"eno", 1},
		{"owt", 2},
		{"eerth", 3},
	}

	input := os.Stdin
	scanner := bufio.NewScanner(input)

	for scanner.Scan() {
		line := scanner.Text()
		term := ""

		for i := range line {
			for _, str := range strings {
				if string.Prefix(i, str) {
					term += str
					break
				}
			}

			for i := range reverseString(line) {
				for _, str := range strings_rev {
					if string.Prefix(i, str) {
						term += str
						break
					}
				}

				parsed_term, err := strconv.Atoi(term)
				if err != nil {
					fmt.Println("Error parsing term")
					return
				}

				sum += parsed_term
			}

			fmt.Println(sum)
		}
	}
}
