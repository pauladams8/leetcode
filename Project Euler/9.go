package main

import (
  "fmt"
  "os"
)

func isTriplet(a int, b int, c int) bool {
  if (a * a + b * b == c * c) {
    return true
  }

  return false
}

func getProduct (a int, b int, c int) int {
  return a * b * c
}

func main() {
  fmt.Println("Finding product of Pythagorean triplet that sums to 1000...\n")

  var aim int = 1000

  for a := 1; a <= aim / 3; a++ {
    for b := a + 1; b <= aim / 2; b++ {
      var c int = aim - a - b
      
      if isTriplet(a, b ,c) {
        product := getProduct(a, b, c)

        fmt.Println("Found!")
        fmt.Println(product)
        fmt.Println("\nFYI the numbers were")
        
        for _, number := range [3]int{a, b, c} {
          fmt.Println(number)
        }

        os.Exit(3)
      }
    }
  }
}