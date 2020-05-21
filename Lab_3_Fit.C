{
	Double_t nMaxNe[4] = {1, 2, 3, 4};
	Double_t vMaxNe[4] = {13.50, 30.50, 48.50, 68.25};
	
	Double_t nMinNe[3] = {1, 2, 3};
	Double_t vMinNe[3] = {21.25, 38.25, 57.25};
	
	Double_t nMaxHg[7] = {1, 2, 3, 4, 5, 6, 7};
	Double_t vMaxHg[7] = {6.656, 11.36, 16.06, 21.10, 25.98, 31.18, 36.39};
	
	Double_t nMinHg[7] = {1, 2, 3, 4, 5, 6, 7};
	Double_t vMinHg[7] = {8.336, 13.21, 18.08, 23.12, 28.33, 33.54, 38.91};
	
	auto maxNe = new TGraph(4, nMaxNe, vMaxNe);
	auto minNe = new TGraph(3, nMinNe, vMinNe);
	auto maxHg = new TGraph(7, nMaxHg, vMaxHg);
	auto minHg = new TGraph(7, nMinHg, vMinHg);
	
	auto f = new TF1("f", "[0]*(x - [1])", 0, 10);
	maxNe->Fit(f);
	minNe->Fit(f);
	maxHg->Fit(f);
	minHg->Fit(f);
	
	maxNe->SetMarkerStyle(21);
	maxNe->SetMarkerColor(4);
	minNe->SetMarkerStyle(25);
	minNe->SetMarkerColor(4);
	maxHg->SetMarkerStyle(22);
	minHg->SetMarkerStyle(26);
	
	auto g = new TMultiGraph();
	g->Add(maxNe);
	g->Add(minNe);
	g->Add(maxHg);
	g->Add(minHg);
	g->SetTitle("Period Number vs Voltage;Period# ;Voltage (V)");
	g->Draw("AP");
	
	auto l = new TLegend(0.6, 0.7, 0.9, 0.9);
	l->SetHeader("Legends");
	l->AddEntry(maxNe, "Neon Maximums");
	l->AddEntry(minNe, "Neon Minimums");
	l->AddEntry(maxHg, "Mercury Maximums");
	l->AddEntry(minHg, "Mercury Minimums");
	l->Draw();
}