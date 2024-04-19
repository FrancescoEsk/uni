# calcolo della binomiale

n <- 18
p <- 1/3

# BINOMIALE
dbinom(3, n, p) # X = 3
sum(dbinom(3:18, n, p)) # X >= 3
sum(dbinom(1:4, n, p)) # 1 <= X < 5
sum(dbinom(15:18, n, p)) # X >= 15

l <- 3

# POISSON
dpois(3, l) # X = 3
sum(dpois(3:18, l)) # X >= 3
sum(dpois(1:4, l)) # 1 <= X < 5
sum(dpois(15:18, l)) # X >= 15

# GRAFICO DELLA BINOMIALE

df_0.5 <- data.frame(x = 0:18,
                     PMF = dbinom(x = 0:18, size = 18, prob = 1/3), CDF = pbinom(q = 0:18, size = 18, prob = 1/3))
ggplot(df_0.5, aes(x = x)) +
  geom_segment(aes(xend = x, y = 0, yend = PMF,
                   color = " PMF")) +
  geom_point(aes(y = PMF, color = " PMF")) +
  geom_step(aes(y = CDF, color = "CDF")) +
  scale_color_manual(values = c("cyan4", "brown3")) +
  scale_x_continuous(breaks = 0:18) +
  labs(color = "Function", x = "Values",
       y = "Probability",
       title = "Binomial distribution",
       subtitle = "n = 18, p = 1/3")


# GRAFICO DELLA POISSON

df_2 <- data.frame(x = 0:18,
                   PMF = dpois(0:18, lambda = 3), CDF = ppois(0:18, lambda = 3))
ggplot(df_2, aes(x = x)) +
  geom_segment(aes(xend = x, y = 0, yend = PMF,
                   color = "PMF")) +
  geom_point(aes(y = PMF, color = "PMF")) +
  geom_step(aes(y = CDF, color = "CDF")) +
  scale_color_manual(values = c("cyan4", "brown3")) +
  scale_x_continuous(breaks = 0:18) +
  labs(color = "Function", x = "Values",
       y = "Probability",
       title = "Poisson distribution",
       subtitle = "lambda = 3")


