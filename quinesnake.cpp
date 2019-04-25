/*bin/ls>/dev/null;sed -n 's/.*.\/\*\(.*\)../\1/p' $0|I=$0 sh;exit;*/std::map<I,
I>m={{97,1},{'w',/*echo g++ -std=c++11 -oo $I -lcurses -DI=int -DF=if -DK=ret\*/
2},{'d',3}};I/*urn -includectime,curses.h,iostream,map,unistd.h|sed s/,/\ -in\*/
w=80,h=28,x=2,y=2,a=2,b=0,d,e,z=768;std::wstring/*clude/g|sh;./o</dev/tty;exit*/
s=LR"x(/*bin/ls>/dev/null;sed -n 's/.*.\/\*\(.*\)../\1/p' $0|I=$0 sh;exit;*/std:
:map<I,I>m={{97,1},{'w',/*echo g++ -std=c++11 -oo $I -lcurses -DI=int -DF=if -DK
=ret\*/2},{'d',3}};I/*urn -includectime,curses.h,iostream,map,unistd.h|sed s/,/\
 -in\*/w=80,h=28,x=2,y=2,a=2,b=0,d,e,z=768;std::wstring/*clude/g|sh;./o</dev/tty
;exit*/s=LR"x%dx";I G(I x,I y){K 3&s[y*w+x]>>8;}I C(I x,I y,I c){(s[y*w+x]&=~z)|
=c<<8;}I P(I d,I &x,I &y){F(d==1)x-=2;!d&&y++;d==2&&y--;F(d==3)x+=2;}I M(){curs_
set(0);I a=rand()%w/2*2,b=rand()%h;timeout(0);F(!G(a,b))C(a,b,2);else M();}I A(I
 x,I y){K s[y*w+x]>>10;}I S(I d){(s[y*w+x]&=~3072)|=d<<10;}I T(){d=A(x,y);F(0<=(
e=getch())&&abs(m[e]-d)!=2)d=m[e];S(d);P(d,x,y);F(x<0||y==h||y<0||x>w-2||G(x,y)&
1)K 0;S(d);F(G(x,y)&2)M();else{s[b*w+a]&=~z;P(A(a,b),a,b);}C(x,y,1);move(0,0);fo
r(I i=0;i<w*h;){attron(e=z&s[i]);addch((char)s[i++]);addch(s[i++]);attroff(e);F(
!(i%w))addch(10);}refresh();K 1;}I main(){srand(time(0));while((e=s.find(10))>0)
s.erase(e,1);s.replace(s.find(L"%d"),2,L"("+s+L")");initscr();start_color();for(
e=0;e<3;){init_pair(e,0,e+9);C(2,e++,1);}noecho();M();while(T())usleep(z<<7);end
win();})x";I G(I x,I y){K 3&s[y*w+x]>>8;}I C(I x,I y,I c){(s[y*w+x]&=~z)|=c<<8;}
I P(I d,I &x,I &y){F(d==1)x-=2;!d&&y++;d==2&&y--;F(d==3)x+=2;}I M(){curs_set(0);
I a=rand()%w/2*2,b=rand()%h;timeout(0);F(!G(a,b))C(a,b,2);else M();}I A(I x,I y)
{K s[y*w+x]>>10;}I S(I d){(s[y*w+x]&=~3072)|=d<<10;}I T(){d=A(x,y);F(0<=(e=getch
())&&abs(m[e]-d)!=2)d=m[e];S(d);P(d,x,y);F(x<0||y==h||y<0||x>w-2||G(x,y)&1)K 0;S
(d);F(G(x,y)&2)M();else{s[b*w+a]&=~z;P(A(a,b),a,b);}C(x,y,1);move(0,0);for(I i=0
;i<w*h;){attron(e=z&s[i]);addch((char)s[i++]);addch(s[i++]);attroff(e);F(!(i%w))
addch(10);}refresh();K 1;}I main(){srand(time(0));while((e=s.find(10))>0)s.erase
(e,1);s.replace(s.find(L"%d"),2,L"("+s+L")");initscr();start_color();for(e=0;e<3
;){init_pair(e,0,e+9);C(2,e++,1);}noecho();M();while(T())usleep(z<<7);endwin();}
