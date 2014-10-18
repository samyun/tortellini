Hours ONLY. True when minutes < 40. Append seconds/minutes to it.

setValue(0x00XX);
setValue(0x80XX);
setValue(0x40XX);
setValue(0xC0XX);
setValue(0x20XX);
setValue(0xA0XX);
setValue(0x60XX);
setValue(0xE0XX);
setValue(0x10XX);
setValue(0x90XX);
setValue(0x50XX);
setValue(0xD0XX);
setValue(0x30XX);

if hours is > 12, hours()-12

Seconds/Minutes only. Minutes < 40

while (minute() <5){
	if (second() % 2 == 0){
		setValue(0xYY00);
	}else{
		setValue(0xYY01);
	}
}
while (minute() < 10){
	if (second() % 2 == 0) {
		setValue(0xYY02);
	}else{
		setValue(0xYY03);
	}
}
while (minute() < 15){
	if (second() % 2 == 0) {
		setValue(0xYY04);
	}else{
		setValue(0xYY05);
	}
}
while (minute() < 20){
	if (second() % 2 == 0) {
		setValue(0xYY08);
	}else{
		setValue(0xYY09);
	}
}
while (minute() < 25){
	if (second() % 2 == 0) {
		setValue(0xYY10);
	}else{
		setValue(0xYY11);
	}
}
while (minute() < 30){
	if (second() % 2 == 0) {
		setValue(0xYY20);
	}else{
		setValue(0xYY21);
	}
}
while (minute() < 35){
	if (second() % 2 == 0) {
		setValue(0xYY40);
	}else{
		setValue(0xYY41);
	}
}
while (minute() < 40){
	if (second() % 2 == 0) {
		setValue(0xYY80);
	}else{
		setValue(0xYY81);
	}
}
while (minute() < 58){
	if (second() % 2 == 0){
		setValue(0xYY00);
	}else{
		setValue(0xYY01);
	}
}


ALL THE THINGS:

if (hour() == 0){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x0000);
		}else{
			setValue(0x0001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x0002);
		}else{
			setValue(0x0003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x0004);
		}else{
			setValue(0x0005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x0008);
		}else{
			setValue(0x0009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x0010);
		}else{
			setValue(0x0011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x0020);
		}else{
			setValue(0x0021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x0040);
		}else{
			setValue(0x0041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x0080);
		}else{
			setValue(0x0081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x0100);
		}else{
			setValue(0x0101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x0200);
		}else{
			setValue(0x0201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x0400);
		}else{
			setValue(0x0401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x0800);
		}else{
			setValue(0x0801);
		}
	}
}
else if (hour() == 1 || hour() == 13){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x8000);
		}else{
			setValue(0x8001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x8002);
		}else{
			setValue(0x8003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x8004);
		}else{
			setValue(0x8005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x8008);
		}else{
			setValue(0x8009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x8010);
		}else{
			setValue(0x8011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x8020);
		}else{
			setValue(0x8021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x8040);
		}else{
			setValue(0x8041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x8080);
		}else{
			setValue(0x8081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x8100);
		}else{
			setValue(0x8101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x8200);
		}else{
			setValue(0x8201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x8400);
		}else{
			setValue(0x8401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x8800);
		}else{
			setValue(0x8801);
		}
	}
}
else if (hour() == 2 || hour() == 14){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x4000);
		}else{
			setValue(0x4001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x4002);
		}else{
			setValue(0x4003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x4004);
		}else{
			setValue(0x4005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x4008);
		}else{
			setValue(0x4009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x4010);
		}else{
			setValue(0x4011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x4020);
		}else{
			setValue(0x4021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x4040);
		}else{
			setValue(0x4041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x4080);
		}else{
			setValue(0x4081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x4100);
		}else{
			setValue(0x4101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x4200);
		}else{
			setValue(0x4201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x4400);
		}else{
			setValue(0x4401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x4800);
		}else{
			setValue(0x4801);
		}
	}
}
else if (hour() == 3 || hour() == 15){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xC000);
		}else{
			setValue(0xC001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xC002);
		}else{
			setValue(0xC003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xC004);
		}else{
			setValue(0xC005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xC008);
		}else{
			setValue(0xC009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xC010);
		}else{
			setValue(0xC011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xC020);
		}else{
			setValue(0xC021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xC040);
		}else{
			setValue(0xC041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xC080);
		}else{
			setValue(0xC081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xC100);
		}else{
			setValue(0xC101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xC200);
		}else{
			setValue(0xC201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xC400);
		}else{
			setValue(0xC401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xC800);
		}else{
			setValue(0xC801);
		}
	}
}
else if (hour() == 4 || hour() == 16){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x2000);
		}else{
			setValue(0x2001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x2002);
		}else{
			setValue(0x2003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x2004);
		}else{
			setValue(0x2005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x2008);
		}else{
			setValue(0x2009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x2010);
		}else{
			setValue(0x2011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x2020);
		}else{
			setValue(0x2021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x2040);
		}else{
			setValue(0x2041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x2080);
		}else{
			setValue(0x2081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x2100);
		}else{
			setValue(0x2101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x2200);
		}else{
			setValue(0x2201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x2400);
		}else{
			setValue(0x2401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x2800);
		}else{
			setValue(0x2801);
		}
	}
}
else if (hour() == 5 || hour() == 17){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xA000);
		}else{
			setValue(0xA001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xA002);
		}else{
			setValue(0xA003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xA004);
		}else{
			setValue(0xA005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xA008);
		}else{
			setValue(0xA009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xA010);
		}else{
			setValue(0xA011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xA020);
		}else{
			setValue(0xA021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xA040);
		}else{
			setValue(0xA041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xA080);
		}else{
			setValue(0xA081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xA100);
		}else{
			setValue(0xA101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xA200);
		}else{
			setValue(0xA201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xA400);
		}else{
			setValue(0xA401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xA800);
		}else{
			setValue(0xA801);
		}
	}
}
else if (hour() == 6 || hour() == 18){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x6000);
		}else{
			setValue(0x6001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x6002);
		}else{
			setValue(0x6003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x6004);
		}else{
			setValue(0x6005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x6008);
		}else{
			setValue(0x6009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x6010);
		}else{
			setValue(0x6011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x6020);
		}else{
			setValue(0x6021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x6040);
		}else{
			setValue(0x6041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x6080);
		}else{
			setValue(0x6081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x6100);
		}else{
			setValue(0x6101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x6200);
		}else{
			setValue(0x6201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x6400);
		}else{
			setValue(0x6401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x6800);
		}else{
			setValue(0x6801);
		}
	}
}
else if (hour() == 7 || hour() == 19){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xE000);
		}else{
			setValue(0xE001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xE002);
		}else{
			setValue(0xE003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xE004);
		}else{
			setValue(0xE005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xE008);
		}else{
			setValue(0xE009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xE010);
		}else{
			setValue(0xE011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xE020);
		}else{
			setValue(0xE021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xE040);
		}else{
			setValue(0xE041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xE080);
		}else{
			setValue(0xE081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xE100);
		}else{
			setValue(0xE101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xE200);
		}else{
			setValue(0xE201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xE400);
		}else{
			setValue(0xE401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xE800);
		}else{
			setValue(0xE801);
		}
	}
}
else if (hour() == 8 || hour() == 20){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x1000);
		}else{
			setValue(0x1001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x1002);
		}else{
			setValue(0x1003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x1004);
		}else{
			setValue(0x1005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x1008);
		}else{
			setValue(0x1009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x1010);
		}else{
			setValue(0x1011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x1020);
		}else{
			setValue(0x1021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x1040);
		}else{
			setValue(0x1041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x1080);
		}else{
			setValue(0x1081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x1100);
		}else{
			setValue(0x1101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x1200);
		}else{
			setValue(0x1201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x1400);
		}else{
			setValue(0x1401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x1800);
		}else{
			setValue(0x1801);
		}
	}
}
else if (hour() == 9 || hour() == 21){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x9000);
		}else{
			setValue(0x9001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x9002);
		}else{
			setValue(0x9003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x9004);
		}else{
			setValue(0x9005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x9008);
		}else{
			setValue(0x9009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x9010);
		}else{
			setValue(0x9011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x9020);
		}else{
			setValue(0x9021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x9040);
		}else{
			setValue(0x9041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x9080);
		}else{
			setValue(0x9081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x9100);
		}else{
			setValue(0x9101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x9200);
		}else{
			setValue(0x9201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x9400);
		}else{
			setValue(0x9401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x9800);
		}else{
			setValue(0x9801);
		}
	}
}
else if (hour() == 10 || hour() == 22){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x5000);
		}else{
			setValue(0x5001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x5002);
		}else{
			setValue(0x5003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x5004);
		}else{
			setValue(0x5005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x5008);
		}else{
			setValue(0x5009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x5010);
		}else{
			setValue(0x5011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x5020);
		}else{
			setValue(0x5021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x5040);
		}else{
			setValue(0x5041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x5080);
		}else{
			setValue(0x5081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x5100);
		}else{
			setValue(0x5101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x5200);
		}else{
			setValue(0x5201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x5400);
		}else{
			setValue(0x5401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x5800);
		}else{
			setValue(0x5801);
		}
	}
}
else if (hour() == 11 || hour() == 23){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0xD000);
		}else{
			setValue(0xD001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0xD002);
		}else{
			setValue(0xD003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0xD004);
		}else{
			setValue(0xD005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0xD008);
		}else{
			setValue(0xD009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0xD010);
		}else{
			setValue(0xD011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0xD020);
		}else{
			setValue(0xD021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0xD040);
		}else{
			setValue(0xD041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0xD080);
		}else{
			setValue(0xD081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0xD100);
		}else{
			setValue(0xD101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0xD200);
		}else{
			setValue(0xD201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0xD400);
		}else{
			setValue(0xD401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0xD800);
		}else{
			setValue(0xD801);
		}
	}
}
else if (hour() == 12){
	while (minute() <5){
		if (second() % 2 == 0){
			setValue(0x3000);
		}else{
			setValue(0x3001);
		}
	}
	while (minute() < 10){
		if (second() % 2 == 0) {
			setValue(0x3002);
		}else{
			setValue(0x3003);
		}
	}
	while (minute() < 15){
		if (second() % 2 == 0) {
			setValue(0x3004);
		}else{
			setValue(0x3005);
		}
	}
	while (minute() < 20){
		if (second() % 2 == 0) {
			setValue(0x3008);
		}else{
			setValue(0x3009);
		}
	}
	while (minute() < 25){
		if (second() % 2 == 0) {
			setValue(0x3010);
		}else{
			setValue(0x3011);
		}
	}
	while (minute() < 30){
		if (second() % 2 == 0) {
			setValue(0x3020);
		}else{
			setValue(0x3021);
		}
	}
	while (minute() < 35){
		if (second() % 2 == 0) {
			setValue(0x3040);
		}else{
			setValue(0x3041);
		}
	}
	while (minute() < 40){
		if (second() % 2 == 0) {
			setValue(0x3080);
		}else{
			setValue(0x3081);
		}
	}
	while (minute() < 45){
		if (second() % 2 == 0){
			setValue(0x3100);
		}else{
			setValue(0x3101);
		}
	}
	while (minute() < 50){
		if (second() % 2 == 0){
			setValue(0x3200);
		}else{
			setValue(0x3201);
		}
	}
	while (minute() < 55){
		if (second() % 2 == 0){
			setValue(0x3400);
		}else{
			setValue(0x3401);
		}
	}
	while (minute() < 60 && minute() > 50){
		if (second() % 2 == 0){
			setValue(0x3800);
		}else{
			setValue(0x3801);
		}
	}
}
