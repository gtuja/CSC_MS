# System Requirements

- SR shall have attributes, i.e., capability, condition, constraint.
- C, System shall retrieve each of button states.
- C, System shall be able to prevent chattering of each buttons.
- C, System shall output each of LED duties.
- Cons, system shall respond to each of button states and LED outputs at every 1ms.
- Cond, Button event shall be notified according to the pressed time, if pressed time is less thn 1s set it to short-pressed or not set it to long-pressed.
- Cons, The match count for button chattering prevention shall be 5.
- Cons, The fade in and out time shall be 1s and 2s.
- Cond, The fade in and out shall be done when the short-pressed button event is notifyed.
- Cond, LEDs shall be changed on and off immediately when th long press button event is notified.

- Create a project.[PM]
- Create a repository.[TPM]
- Create an issue for SwRS analysis.[PM->TPM, branch:=issue#001_RA_SyRS]
- Carry out SyRS analysis and make up SwRS.[TPM]
- Pull request for issuexxx [TPM->PM, Accepted#, Rejected#]
- Report rejected SyRS to System Division.[PM]
- Report SwRS to Evaluation Division.[PM]
- Create an issue for SwDD analysis.[TPM->DEV, branch:=issue#002_RA_SwRS]
- Carry out SwRS analysis and make up SwDD.[TPM]



