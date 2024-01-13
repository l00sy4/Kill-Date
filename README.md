# Kill-Date

The header file provided contains a function that deletes the currently running executable from the disk and terminates the process if the date specified in the macro has been passed. Currently, the date in the macro is hardcoded to 22/2/2024, you can change it to whatever you wish (or parametrize the function).

### Usage

You would probably want to use it in a way similar to this

```C
if(HAS_DATE_PASSED)
{
    // zero out keys and payload data
    SelfDelete();
}
```

### Credits/References

- Initial concept discovered by [Jonas Lykkegaard](https://twitter.com/jonasLyk)
- https://github.com/LloydLabs/delete-self-poc
