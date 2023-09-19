This happens because shell removes double quotes and pass it to insmod, to avoid this add a single quotes over the string.

Run the following command: "insmod argument.ko name='"Linux World"' to pass the whole string

