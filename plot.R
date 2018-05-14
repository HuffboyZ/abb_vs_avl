abb <- file("abb.txt", open = "r")
abbLines <- readLines(abb)
close(abb)

avl <- file("./avl.txt", open = "r")
avlLines <- readLines(avl)
close(avl)

yBound <- c(100)

plot(avlLines, type = "o", ylab = "Comparações", col = "blue", ann = FALSE, ylim = c(0, yBound))
lines(abbLines, type="o", col="red")

title(main = "ABB x AVL", font.main=1)
