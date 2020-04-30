{
	Int_t nKa = 9;
	Double_t xKa[9] = {22, 24, 26, 28, 29, 30, 47, 48, 50};
	Double_t yKa[9] = {sqrt(540.14), sqrt(646.33), sqrt(761.33), sqrt(888.28), sqrt(954.62), sqrt(1023.79), sqrt(2601.60), sqrt(2719.51), sqrt(2963.53)};
	Double_t exKa[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t eyKa[9] = {12.11245/(2*sqrt(540.14)), 12.45055/(2*sqrt(646.33)), 13.47575/(2*sqrt(761.33)), 13.3113/(2*sqrt(888.28)), 13.9919/(2*sqrt(954.62)), 14.0531/(2*sqrt(1023.79)), 18.8693/(2*sqrt(2601.60)), 20.50425/(2*sqrt(2719.51)), 21.25865/(2*sqrt(2963.53))};
	
	Int_t nKb = 9;
	Double_t xKb[9] = {22, 24, 26, 28, 29, 30, 47, 48, 50};
	Double_t yKb[9] = {sqrt(590.15), sqrt(709.56), sqrt(838.40), sqrt(980.28), sqrt(1055.54), sqrt(1133.88), sqrt(2934.55), sqrt(3070.14), sqrt(3347.80)};
	Double_t exKb[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	Double_t eyKb[9] = {10.22735/(2*sqrt(590.15)), 8.44155/(2*sqrt(709.56)), 12.4986/(2*sqrt(838.40)), 11.08335/(2*sqrt(980.28)), 11.91585/(2*sqrt(1055.54)), 12.5862/(2*sqrt(1133.88)), 11.5498/(2*sqrt(2934.55)), 11.0055/(2*sqrt(3070.14)), 14.2399/(2*sqrt(3347.80))};
		
	Int_t nL = 7;
	Double_t xL[7] = {47, 48, 50, 64, 73, 79, 82};
	Double_t yL[7] = {sqrt(368.12), sqrt(386.21), sqrt(414.16), sqrt(724.08), sqrt(966.83), sqrt(1149.41), sqrt(1247.52)};
	Double_t exL[7] = {0, 0, 0, 0, 0, 0, 0};
	Double_t eyL[7] = {15.0398/(2*sqrt(368.12)), 18.5034/(2*sqrt(386.21)), 10.23915/(2*sqrt(414.16)), 12.77/(2*sqrt(724.08)), 13.42905/(2*sqrt(966.83)), 13.764/(2*sqrt(1149.41)), 14.25135/(2*sqrt(1247.52))};

	auto gKa = new TGraphErrors(9, xKa, yKa, exKa, eyKa);
	auto gKb = new TGraphErrors(9, xKb, yKb, exKb, eyKb);
	auto gL = new TGraphErrors(7, xL, yL, exL, eyL);
	
	f = new TF1("f", "[0]*x + [1]", 0, 100);
	gKa->Fit(f);
	gKb->Fit(f);
	gL->Fit(f);
	
	gKa->SetMarkerStyle(22);
	gKa->SetMarkerColor(4);
	gKb->SetMarkerStyle(26);
	gL->SetMarkerStyle(21);
	gL->SetMarkerColor(4);
	
	g = new TMultiGraph();
	g->Add(gKa);
	g->Add(gKb);
	g->Add(gL);
	g->SetTitle("Atomic Number vs sqrt[energy];Atomic Number;1/sqrt[lambda]");
	g->Draw("AP");
}
