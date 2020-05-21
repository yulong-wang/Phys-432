{
	Double_t p[6] = {0, 1, 2, 3, 4, 5};
	Double_t t[6] = {315, 350, 393, 449, 523, 629};
	
	auto tvp = new TGraph(6, t, p);
	
	auto f = new TF1("f", "[0] - [1]/([2] + x)", 300, 650);
	tvp->Fit(f);
	
	tvp->SetMarkerStyle(22);
	tvp->SetMarkerColor(4);
	tvp->SetTitle("Temperature vs log(Pressure);Temperature (K);log(Pressure (Pa))");
	tvp->Draw("AP");
}