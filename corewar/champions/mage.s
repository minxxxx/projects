.name		"Mage"
.comment	"Data potentia est"

cast_buffs:
	sti		r1, %:heal, %1
	sti		r1, %:heal2, %1

heal:
	live	%1
summon_imp:
	fork	%:imp_buff
	fork	%:imp_buff
heal2:
	live	%1
summon_wisp:
	fork	%:wisp_buff
	fork	%:wisp_buff2
	zjmp	%:cast_buffs

imp_buff:
	add		r1, r2, r3
refresh_imp:
	sti		r1, %:heal_imp, %1
heal_imp:
	live	%1
	zjmp	%:refresh_imp

wisp_buff:
	ld		%4, r3
	ld		%42, r4
fireball:
	sti		r1, r4, %4
	add		r3, r4, r4
	zjmp	%:fireball

wisp_buff2:
	ld		%4, r3
	ld		%84, r4
fireball2:
	sti		r1, r4, %4
	add		r3, r4, r4
	zjmp	%:fireball2
