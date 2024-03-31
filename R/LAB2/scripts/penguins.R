# install.packages("palmerpenguins")
library("palmerpenguins")
data(package = "palmerpenguins")
data("penguins")

# media di tutti i valori
mean(penguins$bill_length_mm, na.rm=TRUE)
mean(penguins$bill_depth_mm, na.rm=TRUE)
mean(penguins$flipper_length_mm, na.rm=TRUE)
mean(penguins$body_mass_g, na.rm=TRUE)
mean(penguins$year, na.rm=TRUE)

# deviazione standard
sd(penguins$bill_length_mm, na.rm=TRUE)
sd(penguins$bill_depth_mm, na.rm=TRUE)
sd(penguins$flipper_length_mm, na.rm=TRUE)
sd(penguins$body_mass_g, na.rm=TRUE)
sd(penguins$year, na.rm=TRUE)

# mediana
median(penguins$bill_length_mm, na.rm=TRUE)
median(penguins$bill_depth_mm, na.rm=TRUE)
median(penguins$flipper_length_mm, na.rm=TRUE)
median(penguins$body_mass_g, na.rm=TRUE)
median(penguins$year, na.rm=TRUE)

stat_auto <- function(x){
  return (c(mean(x, na.rm=TRUE), sd(x, na.rm=TRUE)))
}

stat_manual <- function(x){
  x = na.omit(x)
  len = length(x)
  media = sum(x)/len
  sorted = sort(x)
  
  if (len%%2 == 1){
    mediana = sorted[(n-1)/2]
  } else {
    mediana = ( sorted[n/2] + sorted[(n/2)+1] ) / 2
  }
  
  
  return (c(media, mediana, dev))
}