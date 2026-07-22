package lang

import (
	"fmt"
	"strings"
)


func Handler0(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler3(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler4(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler5(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler6(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler7(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler8(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler9(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler10(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler11(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler12(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler13(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler14(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler15(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler16(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler17(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler18(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler19(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler20(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler21(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler22(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler23(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler24(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler25(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler26(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler27(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler28(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler29(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler30(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler31(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler32(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler33(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler34(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler35(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler36(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler37(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler38(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler39(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler40(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler41(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler42(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler43(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler44(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler45(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler46(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler47(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler48(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler49(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler50(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler51(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler52(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler53(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler54(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler55(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler56(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler57(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler58(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler59(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler60(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler61(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler62(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler63(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler64(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler65(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler66(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler67(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler68(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler69(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler70(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler71(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler72(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler73(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler74(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler75(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler76(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler77(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler78(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler79(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler80(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler81(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler82(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler83(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler84(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler85(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler86(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler87(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler88(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler89(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler90(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler91(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler92(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler93(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler94(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler95(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler96(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler97(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler98(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler99(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler100(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler101(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler102(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler103(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler104(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler105(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler106(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler107(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler108(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler109(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler110(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler111(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler112(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler113(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler114(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler115(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler116(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler117(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler118(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler119(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler120(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler121(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler122(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler123(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler124(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler125(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler126(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler127(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler128(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler129(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler130(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler131(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler132(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler133(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler134(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler135(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler136(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler137(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler138(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler139(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler140(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler141(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler142(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler143(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler144(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler145(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler146(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler147(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler148(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler149(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler150(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler151(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler152(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler153(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler154(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler155(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler156(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler157(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler158(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler159(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler160(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler161(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler162(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler163(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler164(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler165(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler166(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler167(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler168(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler169(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler170(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler171(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler172(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler173(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler174(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler175(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler176(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler177(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler178(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler179(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler180(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler181(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler182(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler183(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler184(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler185(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler186(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler187(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler188(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler189(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler190(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler191(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler192(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler193(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler194(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler195(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler196(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler197(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler198(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler199(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler200(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler201(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler202(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler203(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler204(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler205(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler206(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler207(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler208(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler209(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler210(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler211(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler212(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler213(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler214(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler215(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler216(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler217(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler218(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler219(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler220(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler221(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler222(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler223(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler224(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler225(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler226(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler227(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler228(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler229(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler230(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler231(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler232(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler233(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler234(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler235(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler236(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler237(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler238(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler239(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler240(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler241(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler242(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler243(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler244(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler245(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler246(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler247(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler248(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler249(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler250(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler251(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler252(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler253(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler254(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler255(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler256(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler257(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler258(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler259(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler260(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler261(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler262(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler263(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler264(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler265(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler266(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler267(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler268(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler269(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler270(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler271(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler272(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler273(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler274(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler275(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler276(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler277(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler278(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler279(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler280(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler281(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler282(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler283(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler284(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler285(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler286(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler287(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler288(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler289(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler290(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler291(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler292(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler293(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler294(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler295(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler296(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler297(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler298(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler299(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler300(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler301(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler302(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler303(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler304(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler305(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler306(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler307(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler308(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler309(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler310(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler311(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler312(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler313(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler314(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler315(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler316(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler317(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler318(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler319(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler320(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler321(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler322(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler323(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler324(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler325(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler326(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler327(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler328(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler329(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler330(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler331(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler332(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler333(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler334(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler335(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler336(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler337(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler338(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler339(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler340(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler341(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler342(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler343(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler344(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler345(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler346(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler347(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler348(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler349(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler350(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler351(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler352(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler353(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler354(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler355(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler356(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler357(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler358(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler359(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler360(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler361(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler362(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler363(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler364(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler365(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler366(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler367(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler368(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler369(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler370(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler371(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler372(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler373(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler374(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler375(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler376(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler377(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler378(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler379(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler380(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler381(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler382(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler383(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler384(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler385(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler386(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler387(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler388(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler389(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler390(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler391(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler392(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler393(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler394(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler395(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler396(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler397(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler398(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler399(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler400(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler401(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler402(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler403(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler404(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler405(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler406(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler407(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler408(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler409(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler410(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler411(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler412(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler413(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler414(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler415(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler416(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler417(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler418(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler419(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler420(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler421(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler422(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler423(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler424(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler425(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler426(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler427(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler428(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler429(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler430(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler431(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler432(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler433(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler434(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler435(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler436(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler437(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler438(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler439(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler440(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler441(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler442(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler443(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler444(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler445(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler446(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler447(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler448(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler449(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler450(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler451(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler452(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler453(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler454(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler455(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler456(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler457(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler458(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler459(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler460(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler461(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler462(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler463(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler464(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler465(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler466(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler467(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler468(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler469(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler470(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler471(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler472(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler473(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler474(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler475(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler476(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler477(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler478(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler479(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler480(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler481(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler482(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler483(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler484(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler485(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler486(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler487(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler488(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler489(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler490(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler491(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler492(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler493(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler494(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler495(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler496(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler497(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler498(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler499(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler500(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler501(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler502(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler503(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler504(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler505(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler506(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler507(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler508(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler509(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler510(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler511(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler512(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler513(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler514(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler515(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler516(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler517(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler518(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler519(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler520(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler521(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler522(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler523(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler524(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler525(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler526(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler527(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler528(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler529(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler530(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler531(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler532(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler533(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler534(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler535(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler536(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler537(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler538(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler539(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler540(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler541(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler542(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler543(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler544(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler545(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler546(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler547(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler548(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler549(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler550(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler551(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler552(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler553(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler554(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler555(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler556(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler557(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler558(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler559(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler560(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler561(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler562(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler563(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler564(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler565(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler566(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler567(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler568(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler569(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler570(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler571(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler572(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler573(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler574(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler575(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler576(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler577(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler578(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler579(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler580(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler581(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler582(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler583(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler584(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler585(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler586(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler587(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler588(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler589(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler590(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler591(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler592(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler593(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler594(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler595(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler596(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler597(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler598(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler599(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler600(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler601(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler602(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler603(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler604(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler605(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler606(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler607(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler608(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler609(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler610(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler611(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler612(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler613(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler614(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler615(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler616(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler617(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler618(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler619(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler620(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler621(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler622(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler623(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler624(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler625(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler626(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler627(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler628(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler629(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler630(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler631(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler632(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler633(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler634(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler635(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler636(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler637(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler638(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler639(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler640(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler641(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler642(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler643(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler644(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler645(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler646(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler647(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler648(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler649(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler650(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler651(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler652(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler653(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler654(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler655(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler656(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler657(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler658(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler659(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler660(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler661(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler662(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler663(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler664(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler665(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler666(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler667(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler668(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler669(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler670(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler671(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler672(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler673(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler674(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler675(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler676(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler677(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler678(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler679(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler680(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler681(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler682(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler683(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler684(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler685(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler686(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler687(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler688(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler689(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler690(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler691(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler692(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler693(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler694(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler695(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler696(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler697(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler698(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler699(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler700(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler701(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler702(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler703(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler704(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler705(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler706(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler707(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler708(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler709(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler710(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler711(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler712(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler713(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler714(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler715(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler716(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler717(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler718(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler719(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler720(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler721(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler722(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler723(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler724(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler725(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler726(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler727(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler728(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler729(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler730(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler731(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler732(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler733(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler734(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler735(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler736(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler737(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler738(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler739(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler740(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler741(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler742(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler743(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler744(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler745(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler746(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler747(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler748(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler749(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler750(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler751(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler752(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler753(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler754(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler755(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler756(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler757(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler758(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler759(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler760(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler761(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler762(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler763(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler764(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler765(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler766(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler767(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler768(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler769(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler770(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler771(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler772(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler773(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler774(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler775(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler776(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler777(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler778(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler779(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler780(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler781(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler782(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler783(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler784(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler785(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler786(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler787(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler788(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler789(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler790(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler791(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler792(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler793(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler794(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler795(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler796(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler797(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler798(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler799(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler800(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler801(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler802(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler803(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler804(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler805(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler806(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler807(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler808(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler809(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler810(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler811(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler812(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler813(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler814(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler815(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler816(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler817(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler818(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler819(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler820(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler821(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler822(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler823(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler824(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler825(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler826(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler827(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler828(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler829(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler830(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler831(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler832(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler833(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler834(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler835(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler836(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler837(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler838(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler839(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler840(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler841(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler842(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler843(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler844(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler845(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler846(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler847(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler848(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler849(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler850(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler851(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler852(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler853(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler854(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler855(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler856(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler857(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler858(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler859(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler860(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler861(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler862(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler863(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler864(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler865(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler866(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler867(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler868(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler869(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler870(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler871(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler872(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler873(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler874(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler875(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler876(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler877(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler878(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler879(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler880(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler881(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler882(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler883(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler884(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler885(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler886(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler887(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler888(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler889(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler890(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler891(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler892(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler893(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler894(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler895(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler896(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler897(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler898(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler899(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler900(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler901(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler902(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler903(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler904(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler905(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler906(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler907(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler908(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler909(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler910(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler911(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler912(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler913(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler914(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler915(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler916(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler917(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler918(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler919(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler920(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler921(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler922(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler923(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler924(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler925(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler926(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler927(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler928(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler929(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler930(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler931(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler932(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler933(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler934(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler935(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler936(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler937(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler938(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler939(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler940(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler941(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler942(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler943(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler944(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler945(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler946(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler947(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler948(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler949(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler950(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler951(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler952(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler953(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler954(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler955(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler956(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler957(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler958(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler959(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler960(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler961(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler962(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler963(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler964(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler965(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler966(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler967(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler968(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler969(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler970(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler971(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler972(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler973(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler974(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler975(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler976(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler977(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler978(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler979(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler980(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler981(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler982(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler983(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler984(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler985(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler986(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler987(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler988(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler989(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler990(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler991(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler992(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler993(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler994(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler995(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler996(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler997(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler998(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler999(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1000(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1001(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1002(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1003(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1004(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1005(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1006(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1007(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1008(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1009(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1010(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1011(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1012(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1013(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1014(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1015(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1016(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1017(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1018(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1019(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1020(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1021(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1022(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1023(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1024(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1025(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1026(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1027(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1028(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1029(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1030(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1031(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1032(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1033(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1034(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1035(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1036(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1037(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1038(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1039(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1040(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1041(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1042(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1043(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1044(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1045(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1046(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1047(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1048(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1049(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1050(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1051(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1052(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1053(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1054(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1055(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1056(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1057(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1058(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1059(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1060(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1061(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1062(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1063(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1064(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1065(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1066(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1067(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1068(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1069(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1070(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1071(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1072(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1073(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1074(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1075(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1076(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1077(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1078(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1079(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1080(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1081(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1082(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1083(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1084(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1085(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1086(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1087(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1088(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1089(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1090(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1091(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1092(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1093(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1094(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1095(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1096(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1097(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1098(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1099(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1100(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1101(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1102(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1103(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1104(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1105(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1106(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1107(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1108(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1109(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1110(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1111(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1112(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1113(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1114(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1115(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1116(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1117(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1118(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1119(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1120(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1121(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1122(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1123(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1124(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1125(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1126(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1127(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1128(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1129(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1130(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1131(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1132(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1133(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1134(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1135(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1136(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1137(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1138(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1139(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1140(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1141(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1142(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1143(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1144(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1145(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1146(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1147(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1148(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1149(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1150(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1151(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1152(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1153(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1154(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1155(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1156(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1157(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1158(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1159(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1160(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1161(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1162(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1163(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1164(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1165(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1166(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1167(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1168(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1169(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1170(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1171(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1172(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1173(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1174(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1175(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1176(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1177(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1178(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1179(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1180(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1181(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1182(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1183(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1184(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1185(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1186(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1187(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1188(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1189(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1190(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1191(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1192(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1193(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1194(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1195(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1196(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1197(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1198(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1199(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1200(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1201(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1202(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1203(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1204(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1205(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1206(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1207(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1208(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1209(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1210(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1211(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1212(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1213(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1214(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1215(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1216(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1217(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1218(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1219(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1220(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1221(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1222(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1223(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1224(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1225(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1226(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1227(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1228(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1229(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1230(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1231(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1232(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1233(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1234(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1235(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1236(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1237(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1238(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1239(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1240(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1241(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1242(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1243(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1244(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1245(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1246(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1247(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1248(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1249(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1250(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1251(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1252(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1253(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1254(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1255(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1256(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1257(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1258(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1259(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1260(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1261(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1262(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1263(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1264(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1265(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1266(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1267(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1268(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1269(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1270(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1271(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1272(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1273(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1274(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1275(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1276(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1277(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1278(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1279(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1280(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1281(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1282(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1283(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1284(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1285(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1286(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1287(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1288(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1289(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1290(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1291(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1292(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1293(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1294(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1295(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1296(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1297(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1298(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1299(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1300(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1301(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1302(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1303(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1304(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1305(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1306(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1307(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1308(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1309(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1310(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1311(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1312(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1313(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1314(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1315(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1316(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1317(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1318(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1319(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1320(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1321(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1322(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1323(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1324(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1325(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1326(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1327(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1328(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1329(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1330(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1331(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1332(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1333(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1334(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1335(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1336(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1337(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1338(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1339(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1340(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1341(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1342(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1343(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1344(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1345(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1346(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1347(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1348(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1349(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1350(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1351(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1352(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1353(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1354(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1355(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1356(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1357(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1358(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1359(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1360(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1361(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1362(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1363(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1364(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1365(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1366(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1367(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1368(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1369(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1370(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1371(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1372(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1373(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1374(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1375(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1376(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1377(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1378(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1379(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1380(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1381(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1382(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1383(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1384(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1385(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1386(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1387(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1388(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1389(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1390(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1391(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1392(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1393(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1394(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1395(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1396(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1397(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1398(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1399(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1400(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1401(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1402(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1403(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1404(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1405(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1406(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1407(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1408(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1409(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1410(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1411(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1412(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1413(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1414(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1415(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1416(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1417(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1418(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1419(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1420(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1421(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1422(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1423(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1424(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1425(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1426(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1427(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1428(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1429(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1430(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1431(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1432(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1433(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1434(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1435(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1436(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1437(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1438(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1439(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1440(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1441(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1442(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1443(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1444(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1445(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1446(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1447(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1448(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1449(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1450(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1451(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1452(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1453(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1454(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1455(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1456(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1457(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1458(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1459(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1460(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1461(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1462(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1463(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1464(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1465(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1466(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1467(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1468(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1469(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1470(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1471(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1472(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1473(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1474(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1475(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1476(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1477(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1478(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1479(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1480(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1481(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1482(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1483(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1484(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1485(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1486(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1487(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1488(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1489(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1490(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1491(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1492(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1493(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1494(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1495(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1496(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1497(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1498(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1499(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1500(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1501(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1502(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1503(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1504(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1505(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1506(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1507(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1508(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1509(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1510(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1511(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1512(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1513(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1514(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1515(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1516(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1517(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1518(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1519(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1520(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1521(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1522(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1523(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1524(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1525(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1526(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1527(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1528(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1529(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1530(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1531(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1532(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1533(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1534(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1535(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1536(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1537(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1538(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1539(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1540(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1541(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1542(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1543(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1544(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1545(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1546(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1547(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1548(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1549(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1550(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1551(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1552(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1553(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1554(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1555(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1556(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1557(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1558(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1559(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1560(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1561(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1562(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1563(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1564(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1565(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1566(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1567(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1568(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1569(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1570(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1571(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1572(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1573(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1574(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1575(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1576(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1577(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1578(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1579(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1580(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1581(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1582(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1583(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1584(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1585(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1586(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1587(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1588(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1589(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1590(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1591(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1592(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1593(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1594(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1595(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1596(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1597(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1598(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1599(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1600(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1601(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1602(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1603(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1604(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1605(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1606(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1607(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1608(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1609(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1610(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1611(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1612(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1613(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1614(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1615(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1616(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1617(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1618(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1619(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1620(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1621(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1622(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1623(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1624(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1625(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1626(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1627(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1628(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1629(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1630(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1631(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1632(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1633(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1634(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1635(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1636(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1637(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1638(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1639(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1640(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1641(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1642(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1643(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1644(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1645(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1646(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1647(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1648(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1649(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1650(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1651(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1652(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1653(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1654(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1655(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1656(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1657(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1658(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1659(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1660(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1661(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1662(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1663(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1664(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1665(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1666(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1667(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1668(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1669(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1670(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1671(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1672(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1673(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1674(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1675(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1676(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1677(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1678(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1679(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1680(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1681(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1682(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1683(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1684(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1685(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1686(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1687(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1688(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1689(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1690(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1691(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1692(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1693(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1694(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1695(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1696(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1697(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1698(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1699(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1700(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1701(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1702(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1703(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1704(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1705(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1706(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1707(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1708(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1709(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1710(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1711(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1712(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1713(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1714(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1715(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1716(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1717(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1718(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1719(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1720(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1721(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1722(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1723(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1724(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1725(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1726(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1727(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1728(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1729(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1730(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1731(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1732(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1733(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1734(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1735(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1736(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1737(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1738(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1739(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1740(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1741(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1742(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1743(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1744(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1745(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1746(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1747(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1748(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1749(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1750(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1751(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1752(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1753(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1754(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1755(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1756(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1757(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1758(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1759(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1760(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1761(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1762(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1763(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1764(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1765(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1766(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1767(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1768(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1769(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1770(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1771(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1772(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1773(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1774(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1775(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1776(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1777(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1778(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1779(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1780(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1781(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1782(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1783(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1784(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1785(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1786(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1787(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1788(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1789(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1790(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1791(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1792(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1793(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1794(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1795(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1796(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1797(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1798(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1799(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1800(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1801(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1802(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1803(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1804(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1805(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1806(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1807(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1808(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1809(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1810(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1811(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1812(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1813(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1814(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1815(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1816(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1817(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1818(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1819(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1820(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1821(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1822(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1823(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1824(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1825(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1826(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1827(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1828(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1829(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1830(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1831(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1832(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1833(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1834(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1835(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1836(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1837(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1838(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1839(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1840(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1841(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1842(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1843(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1844(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1845(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1846(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1847(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1848(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1849(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1850(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1851(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1852(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1853(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1854(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1855(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1856(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1857(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1858(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1859(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1860(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1861(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1862(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1863(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1864(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1865(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1866(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1867(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1868(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1869(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1870(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1871(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1872(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1873(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1874(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1875(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1876(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1877(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1878(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1879(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1880(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1881(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1882(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1883(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1884(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1885(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1886(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1887(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1888(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1889(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1890(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1891(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1892(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1893(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1894(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1895(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1896(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1897(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1898(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1899(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1900(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1901(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1902(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1903(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1904(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1905(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1906(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1907(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1908(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1909(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1910(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1911(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1912(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1913(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1914(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1915(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1916(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1917(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1918(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1919(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1920(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1921(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1922(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1923(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1924(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1925(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1926(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1927(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1928(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1929(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1930(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1931(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1932(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1933(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1934(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1935(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1936(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1937(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1938(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1939(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1940(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1941(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1942(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1943(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1944(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1945(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1946(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1947(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1948(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1949(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1950(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1951(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1952(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1953(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1954(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1955(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1956(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1957(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1958(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1959(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1960(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1961(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1962(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1963(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1964(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1965(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1966(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1967(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1968(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1969(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1970(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1971(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1972(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1973(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1974(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1975(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1976(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1977(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1978(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1979(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1980(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1981(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1982(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1983(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler1984(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1985(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1986(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1987(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler1988(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1989(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler1990(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler1991(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1992(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1993(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler1994(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler1995(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1996(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler1997(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler1998(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler1999(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2000(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2001(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2002(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2003(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2004(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2005(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2006(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2007(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2008(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2009(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2010(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2011(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2012(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2013(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2014(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2015(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2016(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2017(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2018(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2019(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2020(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2021(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2022(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2023(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2024(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2025(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2026(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2027(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2028(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2029(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2030(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2031(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2032(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2033(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2034(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2035(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2036(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2037(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2038(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2039(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2040(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2041(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2042(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2043(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2044(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2045(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2046(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2047(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2048(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2049(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2050(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2051(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2052(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2053(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2054(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2055(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2056(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2057(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2058(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2059(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2060(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2061(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2062(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2063(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2064(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2065(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2066(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2067(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2068(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2069(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2070(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2071(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2072(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2073(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2074(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2075(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2076(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2077(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2078(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2079(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2080(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2081(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2082(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2083(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2084(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2085(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2086(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*53 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2087(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2088(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2089(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2090(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2091(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2092(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2093(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2094(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2095(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2096(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2097(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2098(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2099(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2100(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2101(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2102(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2103(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2104(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2105(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2106(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2107(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2108(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2109(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2110(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2111(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2112(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2113(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2114(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2115(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2116(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2117(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2118(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2119(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2120(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2121(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2122(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2123(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2124(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2125(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2126(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2127(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2128(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2129(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2130(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2131(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2132(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2133(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2134(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2135(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2136(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2137(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2138(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2139(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2140(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2141(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2142(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2143(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2144(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2145(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2146(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2147(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2148(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2149(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2150(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2151(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2152(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2153(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2154(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2155(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2156(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2157(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2158(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2159(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2160(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2161(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2162(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2163(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*124 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2164(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2165(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2166(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2167(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2168(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2169(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2170(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2171(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2172(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2173(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2174(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2175(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2176(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2177(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2178(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2179(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2180(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2181(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2182(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2183(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2184(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2185(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2186(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2187(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2188(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2189(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2190(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2191(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2192(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2193(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2194(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2195(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2196(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2197(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2198(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2199(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2200(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2201(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2202(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2203(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2204(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2205(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2206(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*61 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2207(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2208(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2209(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2210(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2211(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2212(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2213(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2214(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2215(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2216(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2217(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2218(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2219(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2220(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2221(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2222(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2223(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2224(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2225(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2226(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2227(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2228(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2229(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2230(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2231(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2232(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2233(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2234(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2235(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2236(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2237(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2238(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2239(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2240(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2241(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2242(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2243(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2244(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2245(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2246(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2247(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2248(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2249(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2250(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2251(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2252(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2253(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2254(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2255(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2256(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2257(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2258(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2259(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2260(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2261(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2262(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2263(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2264(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2265(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2266(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2267(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2268(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2269(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2270(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2271(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2272(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2273(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2274(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2275(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2276(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2277(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2278(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2279(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2280(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2281(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2282(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2283(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2284(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2285(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2286(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2287(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2288(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2289(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2290(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2291(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2292(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2293(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2294(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2295(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2296(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2297(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2298(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2299(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2300(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2301(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2302(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2303(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2304(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2305(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2306(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2307(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2308(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2309(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2310(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2311(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2312(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2313(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2314(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2315(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2316(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2317(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2318(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2319(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2320(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2321(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2322(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2323(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2324(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2325(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2326(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2327(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2328(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2329(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2330(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2331(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2332(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2333(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2334(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2335(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2336(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2337(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2338(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2339(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2340(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2341(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2342(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2343(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2344(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2345(name string) string {
	var b strings.Builder
	acc := 39
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2346(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2347(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2348(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2349(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2350(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2351(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2352(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2353(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2354(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2355(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2356(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2357(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2358(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2359(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2360(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2361(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2362(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2363(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2364(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2365(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2366(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2367(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*6 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2368(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2369(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2370(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2371(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2372(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2373(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2374(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2375(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2376(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2377(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2378(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2379(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2380(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2381(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2382(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2383(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2384(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2385(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2386(name string) string {
	var b strings.Builder
	acc := 97
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2387(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2388(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2389(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2390(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2391(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2392(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2393(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2394(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2395(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2396(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2397(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2398(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2399(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2400(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2401(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2402(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2403(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2404(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2405(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2406(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2407(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2408(name string) string {
	var b strings.Builder
	acc := 13
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2409(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2410(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2411(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2412(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2413(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2414(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2415(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2416(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2417(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2418(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2419(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2420(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2421(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2422(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2423(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2424(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2425(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2426(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2427(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2428(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2429(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2430(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2431(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2432(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2433(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*120 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2434(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*128 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2435(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2436(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2437(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2438(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2439(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2440(name string) string {
	var b strings.Builder
	acc := 6
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2441(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2442(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2443(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2444(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2445(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2446(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2447(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2448(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2449(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2450(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2451(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2452(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2453(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2454(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2455(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2456(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2457(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2458(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2459(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2460(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2461(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2462(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2463(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*93 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2464(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2465(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2466(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2467(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2468(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2469(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2470(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2471(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2472(name string) string {
	var b strings.Builder
	acc := 21
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2473(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2474(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2475(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2476(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2477(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2478(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2479(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2480(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2481(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2482(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2483(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2484(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2485(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2486(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2487(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2488(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2489(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2490(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*92 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2491(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*55 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2492(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*88 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2493(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2494(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2495(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2496(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2497(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2498(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*29 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2499(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2500(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2501(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2502(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2503(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2504(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2505(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2506(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2507(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*85 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2508(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2509(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2510(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2511(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2512(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2513(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2514(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2515(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2516(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2517(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2518(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*21 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2519(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2520(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2521(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2522(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2523(name string) string {
	var b strings.Builder
	acc := 90
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2524(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2525(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2526(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2527(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2528(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2529(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2530(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2531(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2532(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2533(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*112 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2534(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2535(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2536(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2537(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2538(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2539(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2540(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2541(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2542(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2543(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2544(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2545(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2546(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*8 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2547(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2548(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2549(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*14 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2550(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2551(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*15 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2552(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2553(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2554(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2555(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2556(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*7 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2557(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2558(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2559(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2560(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2561(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2562(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*32 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2563(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2564(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2565(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2566(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2567(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2568(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2569(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2570(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2571(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2572(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2573(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*80 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2574(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2575(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2576(name string) string {
	var b strings.Builder
	acc := 95
	for i := 0; i < len(name); i++ {
		acc = acc*101 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2577(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2578(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2579(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2580(name string) string {
	var b strings.Builder
	acc := 46
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2581(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2582(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*45 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2583(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2584(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2585(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2586(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2587(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2588(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2589(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*126 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2590(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2591(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2592(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2593(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2594(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*19 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2595(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2596(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2597(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2598(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2599(name string) string {
	var b strings.Builder
	acc := 49
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2600(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2601(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2602(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2603(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2604(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*62 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2605(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2606(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*102 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2607(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2608(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*84 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2609(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2610(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2611(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2612(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*96 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2613(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2614(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*48 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2615(name string) string {
	var b strings.Builder
	acc := 93
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2616(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2617(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2618(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2619(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*114 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2620(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2621(name string) string {
	var b strings.Builder
	acc := 59
	for i := 0; i < len(name); i++ {
		acc = acc*119 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2622(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2623(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2624(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2625(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*58 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2626(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2627(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*38 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2628(name string) string {
	var b strings.Builder
	acc := 9
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2629(name string) string {
	var b strings.Builder
	acc := 42
	for i := 0; i < len(name); i++ {
		acc = acc*39 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2630(name string) string {
	var b strings.Builder
	acc := 8
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2631(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2632(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2633(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2634(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2635(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*110 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2636(name string) string {
	var b strings.Builder
	acc := 34
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2637(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2638(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*57 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2639(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2640(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*20 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2641(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2642(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2643(name string) string {
	var b strings.Builder
	acc := 54
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2644(name string) string {
	var b strings.Builder
	acc := 85
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2645(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2646(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*17 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2647(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*60 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2648(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2649(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*83 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2650(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*131 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2651(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*52 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2652(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2653(name string) string {
	var b strings.Builder
	acc := 87
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2654(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*107 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2655(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2656(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*26 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2657(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2658(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*86 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2659(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*42 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2660(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*28 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2661(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*68 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2662(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*113 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2663(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2664(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2665(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2666(name string) string {
	var b strings.Builder
	acc := 81
	for i := 0; i < len(name); i++ {
		acc = acc*50 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2667(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2668(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*49 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2669(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2670(name string) string {
	var b strings.Builder
	acc := 82
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2671(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*105 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2672(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2673(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*100 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2674(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2675(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2676(name string) string {
	var b strings.Builder
	acc := 20
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2677(name string) string {
	var b strings.Builder
	acc := 7
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2678(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2679(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2680(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2681(name string) string {
	var b strings.Builder
	acc := 71
	for i := 0; i < len(name); i++ {
		acc = acc*37 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2682(name string) string {
	var b strings.Builder
	acc := 17
	for i := 0; i < len(name); i++ {
		acc = acc*104 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2683(name string) string {
	var b strings.Builder
	acc := 83
	for i := 0; i < len(name); i++ {
		acc = acc*54 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2684(name string) string {
	var b strings.Builder
	acc := 73
	for i := 0; i < len(name); i++ {
		acc = acc*13 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2685(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2686(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2687(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2688(name string) string {
	var b strings.Builder
	acc := 60
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2689(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*129 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2690(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2691(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2692(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2693(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2694(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2695(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2696(name string) string {
	var b strings.Builder
	acc := 26
	for i := 0; i < len(name); i++ {
		acc = acc*116 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2697(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2698(name string) string {
	var b strings.Builder
	acc := 67
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2699(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2700(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*5 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2701(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2702(name string) string {
	var b strings.Builder
	acc := 41
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2703(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*78 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2704(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2705(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2706(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2707(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2708(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2709(name string) string {
	var b strings.Builder
	acc := 55
	for i := 0; i < len(name); i++ {
		acc = acc*91 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2710(name string) string {
	var b strings.Builder
	acc := 36
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2711(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*47 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2712(name string) string {
	var b strings.Builder
	acc := 74
	for i := 0; i < len(name); i++ {
		acc = acc*66 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2713(name string) string {
	var b strings.Builder
	acc := 77
	for i := 0; i < len(name); i++ {
		acc = acc*71 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2714(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*108 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2715(name string) string {
	var b strings.Builder
	acc := 25
	for i := 0; i < len(name); i++ {
		acc = acc*98 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2716(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2717(name string) string {
	var b strings.Builder
	acc := 94
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2718(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*99 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2719(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*94 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2720(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*79 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2721(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2722(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2723(name string) string {
	var b strings.Builder
	acc := 61
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2724(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*115 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2725(name string) string {
	var b strings.Builder
	acc := 86
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2726(name string) string {
	var b strings.Builder
	acc := 30
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2727(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*123 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2728(name string) string {
	var b strings.Builder
	acc := 38
	for i := 0; i < len(name); i++ {
		acc = acc*11 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2729(name string) string {
	var b strings.Builder
	acc := 4
	for i := 0; i < len(name); i++ {
		acc = acc*106 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2730(name string) string {
	var b strings.Builder
	acc := 37
	for i := 0; i < len(name); i++ {
		acc = acc*33 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2731(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2732(name string) string {
	var b strings.Builder
	acc := 15
	for i := 0; i < len(name); i++ {
		acc = acc*24 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2733(name string) string {
	var b strings.Builder
	acc := 80
	for i := 0; i < len(name); i++ {
		acc = acc*12 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2734(name string) string {
	var b strings.Builder
	acc := 29
	for i := 0; i < len(name); i++ {
		acc = acc*72 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2735(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*36 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2736(name string) string {
	var b strings.Builder
	acc := 84
	for i := 0; i < len(name); i++ {
		acc = acc*65 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2737(name string) string {
	var b strings.Builder
	acc := 65
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2738(name string) string {
	var b strings.Builder
	acc := 64
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2739(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*31 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2740(name string) string {
	var b strings.Builder
	acc := 57
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2741(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*74 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2742(name string) string {
	var b strings.Builder
	acc := 48
	for i := 0; i < len(name); i++ {
		acc = acc*34 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2743(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2744(name string) string {
	var b strings.Builder
	acc := 47
	for i := 0; i < len(name); i++ {
		acc = acc*77 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2745(name string) string {
	var b strings.Builder
	acc := 50
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2746(name string) string {
	var b strings.Builder
	acc := 58
	for i := 0; i < len(name); i++ {
		acc = acc*73 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2747(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*130 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2748(name string) string {
	var b strings.Builder
	acc := 10
	for i := 0; i < len(name); i++ {
		acc = acc*56 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2749(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*9 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2750(name string) string {
	var b strings.Builder
	acc := 27
	for i := 0; i < len(name); i++ {
		acc = acc*121 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2751(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*64 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2752(name string) string {
	var b strings.Builder
	acc := 23
	for i := 0; i < len(name); i++ {
		acc = acc*127 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2753(name string) string {
	var b strings.Builder
	acc := 28
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2754(name string) string {
	var b strings.Builder
	acc := 66
	for i := 0; i < len(name); i++ {
		acc = acc*63 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2755(name string) string {
	var b strings.Builder
	acc := 31
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2756(name string) string {
	var b strings.Builder
	acc := 35
	for i := 0; i < len(name); i++ {
		acc = acc*118 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2757(name string) string {
	var b strings.Builder
	acc := 62
	for i := 0; i < len(name); i++ {
		acc = acc*90 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2758(name string) string {
	var b strings.Builder
	acc := 78
	for i := 0; i < len(name); i++ {
		acc = acc*16 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2759(name string) string {
	var b strings.Builder
	acc := 76
	for i := 0; i < len(name); i++ {
		acc = acc*46 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2760(name string) string {
	var b strings.Builder
	acc := 63
	for i := 0; i < len(name); i++ {
		acc = acc*40 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2761(name string) string {
	var b strings.Builder
	acc := 44
	for i := 0; i < len(name); i++ {
		acc = acc*76 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2762(name string) string {
	var b strings.Builder
	acc := 18
	for i := 0; i < len(name); i++ {
		acc = acc*75 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2763(name string) string {
	var b strings.Builder
	acc := 79
	for i := 0; i < len(name); i++ {
		acc = acc*41 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2764(name string) string {
	var b strings.Builder
	acc := 5
	for i := 0; i < len(name); i++ {
		acc = acc*23 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2765(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*51 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2766(name string) string {
	var b strings.Builder
	acc := 51
	for i := 0; i < len(name); i++ {
		acc = acc*117 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2767(name string) string {
	var b strings.Builder
	acc := 11
	for i := 0; i < len(name); i++ {
		acc = acc*125 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2768(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2769(name string) string {
	var b strings.Builder
	acc := 3
	for i := 0; i < len(name); i++ {
		acc = acc*3 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2770(name string) string {
	var b strings.Builder
	acc := 40
	for i := 0; i < len(name); i++ {
		acc = acc*69 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2771(name string) string {
	var b strings.Builder
	acc := 16
	for i := 0; i < len(name); i++ {
		acc = acc*43 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2772(name string) string {
	var b strings.Builder
	acc := 53
	for i := 0; i < len(name); i++ {
		acc = acc*30 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2773(name string) string {
	var b strings.Builder
	acc := 12
	for i := 0; i < len(name); i++ {
		acc = acc*35 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2774(name string) string {
	var b strings.Builder
	acc := 24
	for i := 0; i < len(name); i++ {
		acc = acc*25 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2775(name string) string {
	var b strings.Builder
	acc := 75
	for i := 0; i < len(name); i++ {
		acc = acc*67 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2776(name string) string {
	var b strings.Builder
	acc := 14
	for i := 0; i < len(name); i++ {
		acc = acc*89 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2777(name string) string {
	var b strings.Builder
	acc := 91
	for i := 0; i < len(name); i++ {
		acc = acc*95 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2778(name string) string {
	var b strings.Builder
	acc := 43
	for i := 0; i < len(name); i++ {
		acc = acc*27 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2779(name string) string {
	var b strings.Builder
	acc := 32
	for i := 0; i < len(name); i++ {
		acc = acc*70 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 3, acc&0x7fffffff, b.String())
}

func Handler2780(name string) string {
	var b strings.Builder
	acc := 92
	for i := 0; i < len(name); i++ {
		acc = acc*87 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2781(name string) string {
	var b strings.Builder
	acc := 2
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2782(name string) string {
	var b strings.Builder
	acc := 19
	for i := 0; i < len(name); i++ {
		acc = acc*10 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 7, acc&0x7fffffff, b.String())
}

func Handler2783(name string) string {
	var b strings.Builder
	acc := 88
	for i := 0; i < len(name); i++ {
		acc = acc*122 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2784(name string) string {
	var b strings.Builder
	acc := 72
	for i := 0; i < len(name); i++ {
		acc = acc*111 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2785(name string) string {
	var b strings.Builder
	acc := 22
	for i := 0; i < len(name); i++ {
		acc = acc*59 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 4, acc&0x7fffffff, b.String())
}

func Handler2786(name string) string {
	var b strings.Builder
	acc := 33
	for i := 0; i < len(name); i++ {
		acc = acc*97 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 2, acc&0x7fffffff, b.String())
}

func Handler2787(name string) string {
	var b strings.Builder
	acc := 52
	for i := 0; i < len(name); i++ {
		acc = acc*81 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2788(name string) string {
	var b strings.Builder
	acc := 89
	for i := 0; i < len(name); i++ {
		acc = acc*4 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2789(name string) string {
	var b strings.Builder
	acc := 96
	for i := 0; i < len(name); i++ {
		acc = acc*44 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 5, acc&0x7fffffff, b.String())
}

func Handler2790(name string) string {
	var b strings.Builder
	acc := 70
	for i := 0; i < len(name); i++ {
		acc = acc*103 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 9, acc&0x7fffffff, b.String())
}

func Handler2791(name string) string {
	var b strings.Builder
	acc := 45
	for i := 0; i < len(name); i++ {
		acc = acc*22 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 1, acc&0x7fffffff, b.String())
}

func Handler2792(name string) string {
	var b strings.Builder
	acc := 69
	for i := 0; i < len(name); i++ {
		acc = acc*109 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 6, acc&0x7fffffff, b.String())
}

func Handler2793(name string) string {
	var b strings.Builder
	acc := 68
	for i := 0; i < len(name); i++ {
		acc = acc*18 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}

func Handler2794(name string) string {
	var b strings.Builder
	acc := 56
	for i := 0; i < len(name); i++ {
		acc = acc*82 + int(name[i])
		b.WriteByte(name[i])
	}
	return fmt.Sprintf("h-%d-%d-%s", 8, acc&0x7fffffff, b.String())
}
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
