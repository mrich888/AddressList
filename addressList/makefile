OBJ=addressList.o balanceBinarySearchTree.o doubleLinkList.o doubleLinkListQueue.o main.o
TARGET=main
$(TARGET):$(OBJ)
	gcc $^ -o $@

addressList.o:addressList.c
	gcc -c $^ -o $@
balanceBinarySearchTree.o:balanceBinarySearchTree.c
	gcc -c $^ -o $@
doubleLinkList.o:doubleLinkList.c
	gcc -c $^ -o $@
doubleLinkListQueue.o :doubleLinkListQueue.c
	gcc -c $^ -o $@
main.o:main.c
	gcc -c $^ -o $@

clean:
	@rm -rf *.o TARGET