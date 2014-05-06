	xor r2, r2, r2
	sti r1, %:live, %1
live:	live %42
	zjmp %:live
