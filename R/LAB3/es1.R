# write a function to calculate the sum of integer numbers from 1 to n.

sum <- function (n) {
  a <- 0
  for(i in 1:n){
    a <- a + i
  }
  return(a)
}

# write a function to calculate the product of integer numbers from 1 to n
factorial <- function(n) {
  a <- 1
  for(i in 2:n){
    a <- a * i
  }
  return(a)
}

# Try C, but do it recursively
factorialR <- function(n) {
  if(n==0){
    return(1)
  } else {
    return (n * factorialR(n-1))
  }
}

sum(5)
factorial(3)
factorialR(3)
