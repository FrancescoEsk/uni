# A. The first line is the hours of a day, and the second line is the recorded 
#    temperature at each of those times. The first value of 0 for the hours 
#    represents midnight. 

hours <- seq(0, 21, 3) 
temperatures <- c(55.5, 52.4, 52.6, 55.7, 75.6, 77.7, 70.3, 66.6)

# B. Plots the data using black ‘+’ symbols.

par(mfrow = c(1,1))
plot(hours, temperatures, pch = "+")

# C. Note that it is difficult to see the point at time 0 since it falls on the 
#    y-axis. Change the axis range using xlim to improve visualization.

plot(hours, temperatures, pch = "+", xlim = c(-1, 22))

# D. Create a function which takes in input a measure in cm and it returns it in 
# inches (2.54cm = 1inch).

cm2inches <- function(cm){
    return(cm/2.54)
}

# E. Save the plot as a .pdf file in the ./plots directory of the project. Plot 
#    it 10cm x 10cm (see the arguments of the pdf() function).

pdf(file = "./plots/plot_es4.pdf", 
    width = cm2inches(10), 
    height = cm2inches(10))
plot(hours, temperatures, pch = "+", xlim = c(-1, 22))
dev.off()
