students <- 1:100 # crea un vettore con elementi da 1 a 100
grades <- matrix( # crea matrice
    round(runif(1000, 4, 10), digits = 0), # runif = 1000 volte tira fuori un numero da 4 a 10 (con la virgola grazie a round)
    nrow = length(students) # num righe matrice pari al numero degli studenti (quindi 100)
)
# colnames permette di accedere ai nomi delle colonne della matrice grades
colnames(grades) <- paste("Test", seq(1, 10 ,1)) # rinomino le righe con Test 1 fino a Test 10 (seq va da 1 a 10 con passo 1) (potevo anche scrivere 1:10)
rownames(grades) <- paste("Student", students)

avg_grades <- rowMeans(grades)
# vettore che contiene la media di ogni riga della matrice (rowMeans fa media)
best_stud <- which(avg_grades == max(avg_grades)) 
# per ogni valore del vettore avg_grades qual'è la media che corrisponde al massimo delle medie?

cat("The best student is: student", best_stud)
cat("The avg quote of the best student is:", max(avg_grades))


# ciclo for che colloca per ogni riga di insuf quanti voti insufficienti ha ogni studente
insuf <- NULL
for (i in 1:nrow(grades)){
    insuf[i] <- 0
    for(j in 1:ncol(grades)){
        if(grades[i, j] < 6){
            insuf[i] <- insuf[i] + 1
        }
    }
}
# table(insuf) / 100 rende le frequenze assolute a relative
# barplot --> grafico a barre
barplot(table(insuf) / 100, xlab = "Number of insufficient tests",
    ylab = "Relative abundance",
    main = "Relative abundance of insufficients tests")

# by row fa si che la matrice venga compilata per riga (default viene compilata per colonna)
m1 = matrix(1:6, nrow=3, ncol=2, byrow = TRUE)
# m1:

# 1 2
# 3 4
# 5 6
m1[,2] # 2 4 6
m1[2,] # 3 4
m1[2:3, 2] # 4 6
m1[c(1, 3), 2] # 2 6

mat_zero = matrix(0, 3, 3) # matrice 3x3 di zeri
mat_one = matrix(1, 3, 3) # matrice 3x3 di uni
mat_diag = diag(3) # matrice con diagonale principale di uni (e il resto 0)
mat_zero + 1 # somma 1 a tutti gli elementi della matrice
sqrt(mat_one) # esegue la radice quadrata su tutti gli elementi delle matrici 