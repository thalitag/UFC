from itertools import permutations
from itertools import combinations
from itertools import product
#printa a matriz
dets = []
def printMatriz(matriz):
    for i in range(len(matriz[0])):
        for j in range(len(matriz[0])):
            if j == len(matriz[0])-1:
                print(matriz[i][j])
            else:
                print(matriz[i][j] ,end = " ")

            if i == len(matriz[0])-1 and  j == len(matriz[0])-1:
                dets.append(determinant(matriz))
                print('det: ',determinant(matriz))
                print('\n')

def determinant(A, total=0):
    # Section 1: store indices in list for row referencing
    indices = list(range(len(A)))
     
    # Section 2: when at 2x2 submatrices recursive calls end
    if len(A) == 2 and len(A[0]) == 2:
        val = A[0][0] * A[1][1] - A[1][0] * A[0][1]
        return val
 
    # Section 3: define submatrix for focus column and 
    #      call this function
    for fc in indices: # A) for each focus column, ...
        # find the submatrix ...
        As = []
        As.extend(A) # B) make a copy, and ...
        As = As[1:] # ... C) remove the first row
        height = len(As) # D) 
 
        for i in range(height): 
            # E) for each remaining row of submatrix ...
            #     remove the focus column elements
            As[i] = As[i][0:fc] + As[i][fc+1:] 
 
        sign = (-1) ** (fc % 2) # F) 
        # G) pass submatrix recursively
        sub_det = determinant(As)
        # H) total all returns from recursion
        total += sign * A[0][fc] * sub_det 
 
    return total

#faz um loop na matriz e quando encontra um elemento q seja 1 troca-o por -1, printa a matriz e retorna o 1 no lugar do -1
def possibilidadesMatriz(matriz):
    # printMatriz(matriz)
    for i in range(len(matriz[0])):
        for j in range(len(matriz[0])):
            if  matriz[j][i] != -1:
                matriz[j][i] = -1
                printMatriz(matriz)
                matriz[j][i] = 1


#printa a matriz inicial, printa as possibilidades da matriz inicial, apos disso vai adiciondo -1 na matriz, até q seja toda de -1
def main(matriz):
    printMatriz(matriz)
    possibilidadesMatriz(matriz)
    for i in range(len(matriz[0])):
        for j in range(len(matriz[0])):
            matriz[i][j] = -1
            possibilidadesMatriz(matriz)

    print('determinantes: ',sorted(dets))

# creia matriz de dimensao nxn
def retornaMatrizNxN(n):
    M=[]
    for j in range(n):
        l=[]
        for k in range(n):
            l.append(1)
        M.append(l)
    return M


def mainDet():
    n = int(input("Qual a ordem da matriz n x n que deseja verificar os determinantes com entradas iguais a 1 ou-1?\n"))

    k = n*n
    matrizes=[]
    matrizesTransformadas = []
    for j in product((1,-1), repeat=k) :
        matrizes.append(j)
    
    for i in range(len(matrizes)):
        matrizesTransformadas.append(tranformArrayInMatriz(matrizes[i],n))
    
    for l in range(len(matrizesTransformadas)):
        dets.append(determinant(matrizesTransformadas[l]))
    
    dets.sort()

    countDets = []
    finalDets = []
    finalDets.append(dets[0])
    elem = dets[0]
    count = 1
    for p in range(1,len(dets)):
        if(dets[p]==elem):
            count += 1
        else:
            countDets.append(count)
            count = 1 
            elem = dets[p+1]   
            finalDets.append(elem)

        if p == len(dets)-1:
            countDets.append(count)


    print('finalDets: ',finalDets)
    print('countDets: ', countDets)


def tranformArrayInMatriz(array,dim):
    matrix = []
    count1 = 0
    count2 = 0
    row = []
    while count1<len(array):
        row.append(array[count1])
        count1 += 1
        count2 += 1
        if count2==dim:
            matrix.append(row)
            row = []
            count2 = 0
    return matrix        

mainDet()

        