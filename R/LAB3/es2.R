# Simulate the tossing of a fair dice and verify through the definition that 
# the event E = {2, 3} has probability 1/3. S = {1, 2, 3, 4, 5, 6}; E = {2, 3}; P(E) = 1/3
S <- 1:6
E <- c(2,3)
n <- 10000

res <- sample(S, n, replace= TRUE)
nE <- NULL
PE <- 0

# stampo i primi 40 lanci
plot(x=1:40, y=res[1:40], main = "Primi 40 lanci")

for(i in 1:n) {
  if(res[i]==E[1] | res[i]==E[2]) {
    nE[i] <- 1
  } else nE[i] <-0
}

# nE <- res %in% E
# fa la stessa cosa del for sopra, ma crea un vettore con TRUE dove riscontra, e FALSE dove no

# 
PE <- cumsum(nE)/(1:n)

plot(x = 1:n, y=PE, type ="l", log="x")
abline(h=1/3, col = "red")

vettore1 <- c(1:100)
vettore2 <- c(10, 20, 30, 500, 34, 101)

match(vettore2, vettore1)

