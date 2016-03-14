#Powerset/BA Visualization
The motivation for this image was to represent a powerset as the adjacency matrix for a 
directed acyclic graph representing a Boolean poset (i.e. a Hasse diagram). After creating the image 
I found that it resembles certain cellular automata (126, 102), although I have not studied
the latter enough to construct an isomorphism.

### Math Stuff

A partially ordered set is a pair P=(S,R) where S is a set with n elements and R is a reflexive (or irreflexive for a strict ordering), antisymmetric (if a <= b and b <= a then a = b, requires reflexivity), and transitive (a < b and b < c -> a < c) relation (subset of S^2).

A Hasse diagram is a directed acyclic graph associated with a poset (S,E) with vertices in S and edges (uv) in E iff (uv) is in R (i.e. if u<v). The transitive closure is implied when drawing the graph, and the direction of the arrows is usually implied by the "upward" orientation. Check out the wikipedia page ( https://en.wikipedia.org/wiki/Hasse_diagram ) which has 4 different representations of the 4d cube. Also check out the jenn3d program, which is pretty cool for visualizing geometric shapes.

By imposing a linear extension on P (a total order which preserves <), we may construct an adjacency matrix. For the image in this repo, the poset is the Boolean Algebra of sets, which is isomorphic to the set {0,1}^n by just imagining that for a given subset s of S, each element of S is labeled by a zero or 1 according to whether it resides in s. The linear extension used in the image is 
O,a,b,ab,c,ac,bc,abc,d,ad,bd,abd,cd,acd,bcd,abcd
which corresponds to
    ,   a,  b ,  ba, c  , c a,  bc, cba,d   ,d  a,d b ,d ba,dc  ,dc a,dcb ,dcba
0000,0001,0010,0011,0100,0101,0110,0111,1000,1001,1010,1011,1100,1101,1110,1111

or in decimal: 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, the order of the natural numbers!

Interestingly, the set version of the usual numerical order has an efficient recursive structure, while Gray code represents a similar reflective structure but without respect to the numerical order.
