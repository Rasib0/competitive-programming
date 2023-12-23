package main

import (
	"fmt"
	"io"
	"net/http"
)

/* input, err := getInputFromUrl("https://adventofcode.com/2023/day/1/input")
if err != nil {
	fmt.Println("Error getting Input from URL", err)
	return
} */

func getInputFromUrl(url string) (io.ReadCloser, error) {
	response, err := http.Get(url)
	if err != nil {
		fmt.Println("Errror: ", err)
		return nil, err
	}

	defer response.Body.Close()

	if response.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("error: Non-OK status code: %s", response.Status)
	}
	return response.Body, nil
}

func reverseString(input string) string {
	runes := []rune(input)
	length := len(runes)

	for i, j := 0, length-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}

	return string(runes)
}
