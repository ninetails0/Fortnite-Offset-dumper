# RCS FORTNITE OFFSETS Dumper
A simple Fornite offset dumper.


# Info
* **I couldn't get a full source because it's so high in size, you can download it here full src: [Full Source Code Download](https://github.com/DevRcs/Fortnite-Offset-dumper/releases/tag/Fortnite)**

* **You can access ready release here: [Download Release](https://github.com/DevRcs/Fortnite-Offset-dumper/releases/tag/release)**

# _Class()
• `string? Name;` -> The output name of the class. Anything non alphanumeric will be regexed out, and spaces replaced with '_'.
<br> • `string[]? Comments;` => Not currently hooked up. Will add comments before a class in the CodeDom writer.
<br> • `_Offset[]> Offsets;` => Collection of offset classes.

# _Offset()
• `string? Name;` -> The output name of the field. Anything non alphanumeric will be regexed out, and spaces replaced with '_'.
<br> • `string? Pattern;` -> Pattern to scan memory for. All wildcards must be `??`.
<br> • `string? Comment;` -> Not currently hooked up. Will add comment after value in CodeDom writer.
<br> • `int Position;` -> Index + 1 of the last byte before the first wildcard(s) you're scanning for. Will automate this eventually.
<br> • `int Modifier;` -> Any additional values that should be added to located IntPtr.
<br> • `bool MinusOne;` -> Subtract one from the located pointer of the offset. Should be left true in 99% of uses.
<br> • `bool IsFunction;` -> Stops the scanner exactly where the pattern points. Useful for finding scripts/functions.
<br> • `_Level[]? Levels;` -> Extra levels to scan through. Offset will reflect end result.
<br> • `_Field[]? Fields;` -> Extra fields that can be grabbed from the patterns location.

# _Level()
• `int Position;` -> Index + 1 of the last byte before the first wildcard(s) you're scanning for.
<br> • `bool MinusOne;` -> Subtract one from the located pointer of the offset. Should be left true in 99% of uses.

# _Field()
• `ReadType Type;` -> Defines how many bytes the scanner reads for the field (1, 2, 4, 8, 10, 25, or 50).
<br> • `int Position;` -> Index + 1 of the last byte before the first wildcard(s) you're scanning for. Will automate this eventually.
<br> • `string? Name;` -> The output name of the field. Anything non alphanumeric will be regexed out, and spaces replaced with '_'.
<br> • `string? Comment;` -> Not currently hooked up. Will add comment after value in CodeDom writer.

# Packages
• [Reloaded.Memory.SigScan](https://www.nuget.org/packages/Reloaded.Memory.Sigscan/1.2.1) •  [Newtonsoft.Json](https://www.nuget.org/packages/Newtonsoft.Json/13.0.1) • [System.CodeDom](https://www.nuget.org/packages/System.CodeDom/6.0.0)
