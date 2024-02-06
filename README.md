# Kill-Date

The provided header file contains two functions:

- One function that deletes the currently running executable from the disk and then terminates the process. The other retrieves the current Unix timestamp.

There is also a function-like macro that compares the current Unix timestamp with a given epoch.
### Usage

You would probably want to use it in a similar way to this

```C
if(HAS_DATE_PASSED(your_date_in_unix)
{
    // zero out keys and payload data using RtlSecureZeroMemory
    SelfDelete();
}
```

### Credits/References

- Initial concept discovered by [Jonas Lykkegaard](https://twitter.com/jonasLyk)
- https://github.com/LloydLabs/delete-self-poc
