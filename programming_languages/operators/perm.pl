/*find permutation of a list*/
perm([], []).
perm([H|R], L):-
	perm(R, L1),
	insertone(H, L1, L).

insertone(H, L, [H|L]).
insertone(Ele, [H|R], [H|L1]):-
	insertone(Ele, R, L1).
