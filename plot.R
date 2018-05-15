data <- read.table(file.choose(), header=T, sep=" ")

ABBs <- data$ABBs
ABB <- data$ABB
AVL <- data$AVL


ABBs <- sort(ABBs)
ABB <- sort(ABB)
AVL <- sort(AVL)

yBound <- c(300)

plot(ABBs, type = "l", lwd = 4, ylab = "Comparações", col = "blue", ann = FALSE, ylim = c(0, yBound))
lines(ABB, type = "l", lwd = 4, col="red")
lines(AVL, type = "l", lwd = 4, col="black")

title(main = "ABB x AVL", font.main=1)

