/*gcd(A,B,C) produce the greatest common divisor C of A and B*/
/*only support positive number at present*/

gcd(A,A,A):- !.
gcd(A,B,C):-
	A < B,
	!,
	T is B - A,
	gcd(A, T, C).
gcd(A,B,C):-
	T is A-B,
	gcd(T, B, C ).
