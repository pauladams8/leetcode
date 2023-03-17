package main

import (
  "fmt"
  "math"
)

func squareOfSum(n float64) float64 {
  /*
   *   n (n + 1)
   * ( --------- ) ** 2
   *       2
   */
  n = ((n * (n + 1)) / 2)

  n = math.Pow(math.Floor(n), 2)
  
  return n
}

func sumOfSquare(n float64) float64 {
  /*
   *   n (n + 1) (2n + 1)
   * ( ----------------- )
   *            6
   */
   n = (n * (n + 1) * (2 * n + 1)) / 6

   return n
}

func diff (n float64) float64 {
  /*
   * Square of sum - sum of square of sum
   */
  
  diff := squareOfSum(n) - sumOfSquare(n)

  return diff
}

func floatToString (n float64) string {
  n = math.Round(n)

  str := fmt.Sprintf("%v", n)

  return str
}

func main() {
fmt.Println("Differentiate V1.0")

  fmt.Println("A tool to obtain the difference between the square of the sum and the sum of the squares of a given natural number")

  fmt.Println("Built by Paul Adams, 4DAS\n")

  for {
    /*
     * Collect input
     */
    var n float64
    fmt.Println("What number should I compare?")
    fmt.Scan(&n)

    diff := floatToString(math.Floor(diff(n)))

    fmt.Println("\nThe difference is " + diff + "\n")
  }
}