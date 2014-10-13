{
ID: danny_c1
PROG: test
LANG: PASCAL
}

var a, b : word;
	 
begin
   assign(input,'test.in'); reset(input);
   readln(a,b);
   close(input);
   assign(output,'test.in'); reset(output);
   writeln(a+b);
   close(output);
end.
