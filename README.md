# Kill-Date

The header file provided contains:

- Two functions, one that deletes the currently running executable from the disk and terminates the process and one that that gets the current Unix timestamp
- A function-like macro that compares the current Unix timestamp to an epoch

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
