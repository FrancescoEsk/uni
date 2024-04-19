# A laboratory blood test is 99% effective in detecting a certain disease when 
# it is, in fact, present. However, the test also yields a “false positive” 
# (FP – Type I error) result for 1% of the healthy persons tested. If 0.5% of 
# the population actually has the disease, what is the probability a person has 
# the disease given that his test result is positive?

P_EgivenD <- 0.99 # 1st conditional probability, P(E|D) 
P_EgivenDc <- 0.01 # 2nd conditional probability, P(E|Dc) 
P_D <- 0.005 # a priori probability P(D)
P_DE <- P_D*P_EgivenD # P(DE) [TP = true positive]
P_Dc <- (1-P_D) # P(Dc) [TN = true negative]
P_DgivenE <- P_DE / (P_DE + P_EgivenDc * P_Dc) # posterior probability

P_DgivenE
