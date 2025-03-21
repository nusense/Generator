# Liquid Argon Experiment tune

This configuration is the result of requests from SBN and DUNE collaborations.
It is designed to serve as baseline model for SBN analyses. 

The physics content is the following
 - Valencia model for 1p1h, using z-expansion
 - SuSAv2 model for 2p2h
 - Spectral function like approach for the Local Fermi Gas
    - Includes events with SRC-like missing momentum within the bulk of the $p_{miss}$ distribution, 
      but not extending pass the LFG cutoff in $p_{miss}$.
 - The parameters related to pion production are taken from the G18_10a_02_11b tune in order to ensure a better starting point. 
 - De-exitation photons are enabled for Argon