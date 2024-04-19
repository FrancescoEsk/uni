
n <- c(20, 30, 40, 100)
p <- c(1/4, 1/6, 1/8, 1/20)

# for each binomial solution
n * p

PMF <- matrix(NA, nrow=21, ncol=4)
# populo la matrice
for(i in 1:4){
  PMF[,i] <- dbinom(x = 0:20, size=n[i], prob = p[i])
}

# trasformo in un dataframe
PMF <- as.data.frame(PMF)
# nominiamo le colonne
colnames(PMF) <- paste("Binomial", n, round(p,2), sep = "_")

# aggiungo una quinta colonna che contenga la PMF della poisson corrispondente (quella a cui devono approssimare le binomiali)
# dataframe$x aggiunge una colonna di nome x (grazie a $)
PMF$Poisson_5 <- dpois(0:20, lambda = 5)

PMF$x <- 0:20

library(reshape2)

df_to_plot <- melt(PMF, id.vars = "x")

library(RColorBrewer)

# manca da completare il plot
ggplot(data = df_to_plot, aes(x = x, y = 0))


