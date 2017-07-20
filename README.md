# c_world
Random C/C++ musings. Nothing terribly useful, but trying to freshen up my skills.

I ask a lot of these types of questions when I interview candidates, so I figured I should be able to answer them myself. Of course I ask them in Javascript since I'm interviewing people after the invention of the steam engine, so I figured I'd put the answers up in C++, because if I'm interviewing you, and you're motivated enough to find my github, find these files, translate them out of digital Aramaic, and use that to cheat on an interview question, holy shit, I'm hiring you. Hell, if I could get a candidate to show up at an interview with a working knowledge of `switch` statements that knows more about object-oriented programming than what they can misquote from some hipster React video I'll hire them. Honestly, if you say "lambda", and I say "Church" and you say "What?" I'm going to slap you. If you describe a POST route as having "no side effects", I hate you. If I could just get a candidate that didn't describe a CRUD route as "purely functional", I would be so very happy. But I digress.

Note: None of these files are any good. Some do what they say on the tin, none have manuals. Please don't try to use any of this.

That being said, there's a handful of fun whatsits I got bored and put together.

`encryption.cpp` is a simple example of SP encryption. Not meant as a competitor to AES, more just a "Hello World" of encryption. -It's techy and doesn't always work, but it worked on the image last I tried it, despite eating the text file. Well, it's more of a grazer, it only ate the last three lines.- Well, now it works

`file_mod.cpp` does what is says on the tin. It's just an example of how to file reading and writing, because I'd forgotten how to do that since I haven't looked at C++ since high school.

`file_mod_bin.cpp` is binary file modification as a header because I needed it for the encryption thing to work. I'm thinking about tweaking the encryption thing to use streams again so I can stream data into it, but I still need the bin to work on the key.

`key.key` is not a real key, it was just what I was using to test the encryption bit. Please do not use that as a key for anything. Ever.

`sieve.cpp` is the Sieve of Eratosthenes. I'm going to add a key exhange as soon as I refresh my networking-fu because I had forgotten why I don't write C++ any more after years of writing in civilized languages where everything is pre-built and ready to play with. Anyway, I digress. This baby is the least efficient algorithm for generating primes. Well maybe not least, but it's pretty awful and I strongly recommend you don't use it, but if you do, it'll generate some hefty ones for you. If you've got the time, she'll go up to 4294967295. Which obviously isn't prime.

`primeCheck.cpp` was used to check the output for `sieve.cpp`. It is also horribly inefficient. Dear god, find something better.

`bTree.cpp` doesn't work a lick. Some day I'll give a shit. Today is not that day. Anyone who asks you about binary trees is a hack. Tell them I said that. I do have a working Node.JS version somewhere else, self-balancing and everything, but implementing that in C++ quickly turned into not fun, so I stopped.

`canIncrement.cpp` and `version.hpp` do semantic versioning stuff. I've forgotten exactly what, but I was going to use them in some kind of `package.json` incrementer and commit check updater thing. I never got around to it.

`hello_world.cpp`, `fibonacci.cpp`, and `fizzbuzz.cpp` do exactly what they say on the tin.

The rest of the crap is either output from one of these things or was used to test something. Often both, because I use these bits as I see fit.

