Insiduous 20150520.1216:
  Re-arranged the directory. Initial INO didn't work, and I decided that
  subdirs for non-catastrophic tests was apropos. Things to test and CAN
  fail can belong therein.

zarboz 20150524.2305:
  Changed out master branch with Exp branch including code for i2c display
  introduced coding for digipot part #X9C103SIZ 100 ohm digital pot 
  pots are intended to be run in series meaning 1 step will equal 2 ohms
  currently is coded for use of acs712 soon to be overhauld for an lm4040
  to gain a higher accuracy rate of reading.

zarboz 20150524.2313:
  Made branch containing experimental lm4040 coding in place of acs712
  refer to branch lm4040 will do testing to see which is more accurate
  prefer the ability to read amperage with hall sensor even though it is
  calculated. Will recreate coding with lm4040
