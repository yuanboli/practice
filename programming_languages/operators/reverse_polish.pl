rpn([], 0).
rpn([A], A).
rpn([A, B, '+'|R], K):- T is A + B, rpn([T|R], K).
rpn([A, B, '-'|R], K):- T is A - B, rpn([T|R], K).
rpn([A, B, '*'|R], K):- T is A * B, rpn([T|R], K).
rpn([A, B, '/'|R], K):- T is A / B, rpn([T|R], K).
