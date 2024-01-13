# Kill-Date

The header file provided contains a function that deletes the currently running executable from the disk and terminates the process if the date specified in the macro has been passed. You would also probably want to zero out keys and payload data using `RtlSecureZeroMemory`


### Credits/References

- Initial concept discovered by [Jonas Lykkegaard](https://twitter.com/jonasLyk)
- https://github.com/LloydLabs/delete-self-poc
