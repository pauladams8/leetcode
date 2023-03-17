package main

import (
  "fmt"
  "strconv"
)

func getPaths (gridSize int) int {
  paths := 1

  for i := 0; i < gridSize; i++ {
    paths *= (2 * gridSize) - i
    paths /= i + 1
  }

  return paths
}

func formatGridSize (gridSize int) string {
  grid := toString(gridSize)

  return grid + " x " + grid
}

func toString (i int) string {
  return strconv.Itoa(i)
}

func main() {
  var gridSize int

  fmt.Println("Type a grid size (in the format i to represent an i by i grid)") // request grid size
  fmt.Scan(&gridSize) // capture input to paths

  paths := getPaths(gridSize)

  gridKey := formatGridSize(gridSize)

  fmt.Println("\nThere are " + toString(paths) + " possible paths in a grid of size " + gridKey + ".")
}