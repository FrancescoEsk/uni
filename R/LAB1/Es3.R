# A. Load the sunspot.year dataset from the datasets package. Use 
#    data("sunspot.year") and then sunspot.year to load it in the workspace.

data("sunspot.year")
sunspot.year

# B. See the documentation to obtain information about the dataset and create a 
#    sequence vector corresponding to the years. Call this variable year. 

help("sunspot.year")
year <- 1700:1988

# C. Create a variable called sunspot, containing the values from the dataset.

sunspot <- sunspot.year

# D. Put together the variables into a data.frame object.

df <- data.frame(year = year,
                 sunspot = sunspot)

# E. Make a line plot of sunspots vs. year.

# par(mfrow = c(1,1))
plot(df$year, df$sunspot, type = "l")

# F. Superimpose data points as red asterisks. Add a second layer to the plot 
#    by using the points() function. Use pch = "*" and col = "red" in the 
#    points() arguments. 


plot(df$year, df$sunspot, type = "l")
points(x = df$year, y = df$sunspot, pch = "*", col = "red")

# G. Create a title  ‘Sunspots by year’.

plot(df$year, df$sunspot, type = "l", xlab = "Year", ylab = "Spots",
     main = "Sunspots by year")
points(x = df$year, y = df$sunspot, pch = "*", col = "red")

# H. Make a column with 3 panels for the plot created in G., a barplot of spots, 
#    and a histogram of spots.

par(mfrow = c(3, 1))

plot(df$year, df$sunspot, type = "l", xlab = "Year", ylab = "Spots",
     main = "Sunspots by year")
points(x = df$year, y = df$sunspot, pch = "*", col = "red")

barplot(as.vector(df$sunspot), main = "Sunspots - Barplot")

hist(df$sunspot, main = "Sunspots - Histogram", xlab = "Sunspots")

# I. Save the plot in the ./plots directory of the project as a .png image

png(filename = "./plots/plot_es3.png")

par(mfrow = c(3, 1))

plot(df$year, df$sunspot, type = "l", xlab = "Year", ylab = "Spots",
     main = "Sunspots by year")
points(x = df$year, y = df$sunspot, pch = "*", col = "red")

barplot(as.vector(df$sunspot), main = "Sunspots - Barplot")

hist(df$sunspot, main = "Sunspots - Histogram", xlab = "Sunspots")

dev.off()

# J. Save the data frame as a .csv file in the ./data directory of the project.

write.csv(df, file = "./data/sunspots.csv")


