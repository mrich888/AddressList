OBJ=addressList.o balanceBinarySearchTree.o doubleLinkList.o doubleLinkListQueue.o main.o
TARGET=main
$(TARGET):$(OBJ)
	gcc $^ -g -o $@

addressList.o:addressList.c
	gcc -g -c $^ -o $@
balanceBinarySearchTree.o:balanceBinarySearchTree.c
	gcc -g -c $^ -o $@
doubleLinkList.o:doubleLinkList.c
	gcc -g -c $^ -o $@
doubleLinkListQueue.o :doubleLinkListQueue.c
	gcc -g -c $^ -o $@
main.o:main.c
	gcc -g -c $^ -o $@

clean:
	@rm -rf *.o TARGET