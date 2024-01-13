# Kill-Date

The header file provided contains two functions: 

- HasDatePassed() : Checks if a specified date has passed
- SelfDelete(): Deletes the currently running executable from the disk and terminates the process


### Usage

To use it you would need to include the header file, and implement something similar to

```C
if (HasDatePassed(23, 2, 2024)
{
  // RtlSecureZeroMemory() clean up all keys and data used
  SelfDelete();
}
```

### To-do
- Replace HasDatePassed() with a macro

### Credits/References

- Initial concept discovered by [Jonas Lykkegaard](https://twitter.com/jonasLyk)
- https://github.com/LloydLabs/delete-self-poc
