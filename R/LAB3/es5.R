# A. Four people are in a room. What is the probability that no two of them 
#    celebrate their birthday on the same day of the year?
n <- 4 # number of people
d <- 365 # days in a year
# Number of ways I can choose 4 distinct dates in 365 days
# By multiplying by the factorial I am considering all the 
# permutations of those 4 days
n_Bday <- choose(d,n) * factorial(n)
# Divide by the number of possible values to obtain the probability
P_different_Bday <- n_Bday / d^n

# B. n people are in a room. What is the probability that no two of them 
#    celebrate their birthday on the same day of the year? Try this with n from 
#    1 to 100 and plot the probability for each value of n.
people <- 1:100 # A sequence of people
d <- 365 # Days in a year
P_different_Bday <- vector(mode = "numeric", length = n)
for(n in people)
  P_different_Bday[n] <- choose(d,n) * factorial(n) / d^n

df_to_plot <- data.frame("N_people" = people, 
                         "P_different_Bday" = P_different_Bday)

ggplot(data = df_to_plot, aes(x = N_people, y = P_different_Bday)) + 	
  geom_line() +
  ggtitle("P(no Bday on the same day)")

