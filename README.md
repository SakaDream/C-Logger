# C-Logger
Simple colorful C / C++ Logger

![](https://lh3.googleusercontent.com/CH04EjRJp4Tl8yQyVomRsTBr1m40s7tkWXrC2oppiELki_lGJ18ub99KB7IntnspqixW3Yw4nyvEiaKNx5jlvyb5LAASF6KtaD-5oIkfjkM3IhjnCNfyXZyVZfM8ZqL6fV9dlGmT4Q0LuVM_o4Q7Q7QPpkWsuHzHF6VR0B4wAnpAiKuhISoWjCbmLHC4DFp09gfv94vVqxavqEtNcSXuS6d5_Di-GX-IwC6Yr9oTwhliY8GwdxPObKwQXVlRklWITg2pEMYj8TQZbUGQemUGXgMSBXbnTFPw90CYSOhrZ_4qOC5bMnA2tLJPB3Rn0zm0SBwTDMU8bvZ0Y2koULFfF-kpCaoOX7CzcIbzYW3jQD7Fuvdr3-QPyBzkc4Yyi8u_oiWfS9KSaSVrx-5w7QEha0YG2qSoTTqW3EqxpEjtYaTeLE-D4qHX7gG4oM1nLCOiU440dPQpeToIRpRRVto5t_SvtgLIz7B18Tm81ZUbk9CYHkUX618Wmktzc-0-LaWUu5WZUiaVZ5PBbEWNDRMj6lL1mMVa6jGEDjhLQO3trIChpEzfyrTogA0z7_sgqjBqToYmh3dpYOBdjNeEWlZB6rdaHmXa5DlK-U9Mvh6s9LWkszU6KDE59HqzYNkP2BnogyqFnklPInRW7gXhCR6znYG7ew8UEq8MaXyxOnIp-w=w818-h677-no)

# List of files
- **log.h**: Logger header file without program's execute time
- **logwt.h**: Logger header file with program's execute time

# How to use
Simple include `log.h` or `logwt.h` to your C source code
- `debug(Message, [arguments])` : Show debug message
- `log_err(Message, [arguments])` : Show error message
- `log_warn(Message, [arguments])` : Show warning message
- `log_info(Message, [arguments])` : Show info message
- `check(Conditional, Message, [arguments])` : Check if `Conditional` is false, return `Error Message` and goto `error` label
- `check_mem(Object / Variable)` : Check `Object` or `Variable` created into memory
- `check_debug(Conditional, Message, [arguments])` : Check if `Conditional` is false, return `Debug Message` and goto `error` label
- `sentinel(Message, [arguments])` : Same as `log_err()` and goto `error` label

# Color
- Time: Magenta
- Debug Log: Cyan
- Error Log: Red
- Info Log: Default Terminal Text Color

# Credits
- This tool is based by debug tool on the book **Learn C The Hard Way** by **Zed A. Shaw**