class Noganum
  Base=100000000000000000000000000000000000000000000000000000000000000000000000000000000000000
  def initialize(init_int=0,init_frac=0)
    @int=init_int
    @frac=init_frac
  end
  attr_accessor :int, :frac
  
  def printnum()
    print @int,".",@frac,"\n"
  end

  def <=> (a)
    @int=a.int
    @frac=a.frac
  end

  def add(a)
    @int += a.int
    @frac += a.frac
    if @frac > Base
      @int+=1
      @frac-=Base
    end
    return self
  end

  def sub(a)
    @int-=a.int
    @frac-=a.frac
    if @frac<0
      @frac+=Base
      @int-=1
    end
    return self
  end

  def mul(a)
    @int *= a
    @frac*= a
    up = @frac/Base
    @int += up
    @frac-= up*Base
    return self
  end

  def div(a)
    tmp = @int.divmod(a)
    @int = tmp[0]
    @frac,zan = (tmp[1]*Base+@frac).divmod(a)
    if zan>a/2
      @frac+=1  #lÌŒÜ“ü
    end
    return self
  end

  def + (a)
    tmp=Noganum.new(@int,@frac)
    tmp.add(a)
  end

  def - (a)
    tmp=Noganum.new(@int,@frac)
    tmp.sub(a)
  end

  def * (a)
    tmp=Noganum.new(@int,@frac)
    tmp.mul(a)
  end

  def / (a)
    tmp = Noganum.new(@int,@frac)
    tmp.div(a)
  end
  

end

def myatan(a)
  ret = Noganum.new(0)
  tmp = Noganum.new(1)

  tmp.div(a)
  ret.add(tmp)

  deno = 3
  while tmp.int!=0 || tmp.frac!=0
    tmp.div(a)
    tmp.div(a)
    ret.sub(tmp/deno)
    deno += 2
    
    tmp.div(a)
    tmp.div(a)
    ret.add(tmp/deno)
    deno += 2
  end
  
  ret
end

(myatan(5)*16-myatan(239)*4).printnum

