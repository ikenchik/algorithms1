//int[] mass = new int[] { 2, -3, -4, 6, 8, -77, 21, 109, 91, -8, -32 };
//Console.WriteLine($"Первый положительный элемент: {mass.FirstOrDefault(n => n > 0)}");
//Console.WriteLine($"Последний отрцательный элемент: {mass.LastOrDefault(n => n < 0)}");



//int D = 1;
//int[] A = new int[] { 22, 34, -185, 3, -4, 71, -91, 6 };
//Console.Write(A.FirstOrDefault(n => n > 0 & n % 10 == D));



//int L = 6;
//string[] A = new string[] { "5fds", "ghtj", "FBI", "watchingyou", "7yuy&7", "6chain", "6oaoao", "67jkfdd" };
//var _A = A.LastOrDefault(n => char.IsDigit(n[0]) & (n.Length == L), "Not found");
//Console.Write(_A);



/*int D = 2;
int[] A = new int[] { -1, 2, 3, 4, 5, 6, -7, 8, -9, 10 };
var a = A.SkipWhile(n => n <= D).Where(n => n % 2 != 0 && n > 0).Reverse().ToArray();
foreach(int num in a)
{
    Console.Write($"{num} ");
}*/



/*int K = 2;
string[] A = new string[] { "rew", "fdsa", "gffdjsk", "Ght" };
var a = A.SkipWhile(n => Array.IndexOf(A, n) <= K).Where(n => n.Length % 2 != 0 & Char.IsUpper(n[0])).Reverse().ToArray();
for (int i = 0; i < a.Length; i++)
{
    char[] revnum = a[i].ToCharArray();
    Array.Reverse(revnum);
    a[i] = new string(revnum);
}
foreach(string h in a)
{
    Console.Write($"{h} ");
}*/



/*int D = 7;
int K = 9;
int[] A = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
var f = A.TakeWhile(x => x <= D);
var s = A.Skip(K - 1);
var r = f.Union(s).OrderByDescending(x => x);
foreach(var h in r)
{
    Console.Write($"{h} ");
}*/



/*int K = 7;
int[] A = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
var f = A.Where(x => x % 2 == 0).Distinct();
var s = A.Skip(K).Distinct();
var r = f.Except(s).Reverse();

foreach(var h in r)
{
    Console.Write($"{h} ");
}*/



/*int K = 2;
string[] A = new string[] { "911SOS", "PO78", "ROR", "1ABC", "HHH", "OMG", "G" };
var f = A.Take(3 * K);
var l = Array.FindLastIndex(A, s => Char.IsDigit(s[s.Length - 1]));
var s = A.Skip(l + 1).Distinct();
var r = f.Intersect(s).OrderBy(s => s.Length);
foreach (var h in r)
{
    Console.Write($"{h} ");
}*/



