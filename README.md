# Kill-Date

The header file provided contains two functions:

- One function that deletes the currently running executable from the disk and then terminates the process. The other retrieves the current Unix timestamp.

Additionally, there is a function-like macro that compares the current Unix timestamp to a given epoch.

### Usage

You would probably want to use it in a way similar to this

```C
if(HAS_DATE_PASSED(your_date_in_unix)
{
    // zero out keys and payload data
    SelfDelete();
}
```

### Credits/References

- Initial concept discovered by [Jonas Lykkegaard](https://twitter.com/jonasLyk)
- https://github.com/LloydLabs/delete-self-poc
