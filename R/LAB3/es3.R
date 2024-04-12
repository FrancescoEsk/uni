# Simulate the tossing of a fair dice and consider the following events: 
# A = {1, 2}; B= {2, 3, 6}; C = {1, 4, 5}. (hint: compute P(A), P(B) e P(C)).
A <- c(1, 2)
B <- c(2, 3, 6)
C <- c(1, 4, 5)

S <- 1:6
n <- 10000
res <- sample(S, n, replace=TRUE)

nA = 0
nB = 0
nC = 0

for(i in 1:n) {
  if(res[i]==A[1] | res[i]==A[2]) {
    nA[i] <- 1
  } else nA[i] <-0
}
PA <- cumsum(nA)/(1:n)

for(i in 1:n) {
  if(res[i]==B[1] | res[i]==B[2] | res[i]==B[3]) {
    nB[i] <- 1
  } else nB[i] <-0
}
PB <- cumsum(nB)/(1:n)

for(i in 1:n) {
  if(res[i]==C[1] | res[i]==C[2] | res[i]==C[3]) {
    nC[i] <- 1
  } else nC[i] <-0
}
PC <- cumsum(nC)/(1:n)

