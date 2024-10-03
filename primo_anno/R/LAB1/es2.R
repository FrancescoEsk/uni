
# A
1:10
seq(1,10,1)

seq(2,12,5)

# B
mymat <- matrix(0, nrow = 4, ncol = 2)
mymat[2, ] <- c(3, 6)

# C
x <- seq(-pi, pi, length.out = 20)
y <- sin(x)

# D
vet <- -5:5
mat <- matrix(sample(vet, size = 24, replace=TRUE), nrow=4, ncol=6)
# set.seed(number) posso impostare il seed fisso, avendo sempre lo stesso sample
mat_pos <- matrix(abs(mat), nrow=4, ncol=6)

# E
x <- seq(-2,2,0.1)
y <- exp(x)
plot(x, y, main="Esponenziale di x", xlab="x", ylab="y") # plot crea un grafico dando x e y

# F
x <- seq(1,100,5)
y <- sqrt(x)

# sistemo i dati in una finestra grafica composta da 1 riga e 2 colonne
par(mfrow=c(1,2))
plot(x,y)
barplot(x,y)
