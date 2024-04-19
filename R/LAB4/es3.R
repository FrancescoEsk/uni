N <- 1000
p <- 0.8

numeri <- rbinom(N, 9, p)

df <- as.data.frame(numeri)

# vettore di probabilità teoriche
p_teoriche <- as.data.frame(dbinom(x = 0:9, size = 9, prob = 0.8))


ggplot(data = df, aes(x = numeri)) + 
  geom_bar() + 
  labs(x = "Successi", y="Frequenza") +
  geom_point(data = p_teoriche, aes(x = 0:9, y = p), color="red")