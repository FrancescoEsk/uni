# A. Simulate the tossing of a fair dice and consider the following events:
#    A = {1, 2}; B = {2, 3, 6}; C = {1, 4, 5}.

# Define the 3 events
A <- c(1, 2)
B <- c(2, 3, 6)
C <- c(1, 4, 5)

# Number of experiments
n <- 10^5

# Simulate the launches
set.seed(123)
res <- sample(x = 1:6, size = n, replace = TRUE)

# Initialize the successes for each event and their intersections
nA <- nB <- nC <- nAB <- nBC <- 0
# Populate the vector of successes
for(i in seq_len(n)){
  nA[i] <- sum(res[i] == A)  
  nB[i] <- sum(res[i] == B)    
  nC[i] <- sum(res[i] == C)    
  
  nAB[i] <- sum(res[i] == A) & sum(res[i] == B)
  nBC[i] <- sum(res[i] == B) & sum(res[i] == C)
}

# # Without the for loop, using the is.element() and intersect() functions
# nA <- is.element(res, A)
# nB <- is.element(res, B)
# nC <- is.element(res, C)
# nAB <- is.element(res, intersect(A, B))
# nBC <- is.element(res, intersect(B, C))

pA <- cumsum(nA) / (1:n)
pB <- cumsum(nB) / (1:n)
pC <- cumsum(nC) / (1:n)
pAcB = cumsum(nAB) / cumsum(nB) # P(A) = P(A|B) ==> A and B are independent
pBcC = cumsum(nBC) / cumsum(nC) # B and C are dependent

# B. Verify that A and B are independent and that B and C are dependent.

df <- data.frame("index" = 1:n, pA, pB, pC, pAcB, pBcC)
ggplot(df) + 
  geom_line(aes(x = index, y = pA, color = "P(A)")) + 
  geom_line(aes(x = index, y = pAcB, color = "P(A|B)")) +
  geom_hline(aes(yintercept = 1/3), linetype = "dashed", color = "red") +
  scale_x_continuous(trans = "log10") + 
  scale_color_manual(name = "Probabilities", values = c("purple", "green")) +
  theme(legend.position = "bottom") + 
  labs(y = "P(A) and P(A|B)", x = "Launches")

ggplot(df) + 
  geom_line(aes(x = index, y = pB, color = "P(B)")) + 
  geom_line(aes(x = index, y = pBcC, color = "P(B|C)")) +
  geom_hline(aes(yintercept = 1/2), linetype = "dashed", color = "red") +
  scale_x_continuous(trans = "log10") + 
  scale_color_manual(name = "Probabilities", values = c("blue", "orange")) +
  theme(legend.position = "bottom") + 
  labs(y = "P(B) and P(B|C)", x = "Launches")
